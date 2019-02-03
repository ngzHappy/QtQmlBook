#include "ScatterSeriesHelp.hpp"

constexpr const auto static varPI = 3.141592654;
constexpr const auto static varMarkSize = 30;

inline static QImage getBrushFileName() {
    QPainterPath starPath;
    static_assert(varMarkSize > 2);
    starPath.moveTo(varMarkSize - 2, double(varMarkSize)*0.5);
    for (int i = 1; i < 5; ++i) {
        starPath.lineTo(14 + 14 * std::cos(0.8 * i * varPI),
            15 + 14 * std::sin(0.8 * i * varPI));
    }
    starPath.closeSubpath();

    QImage star(varMarkSize, varMarkSize, QImage::Format_ARGB32);
    star.fill(Qt::transparent);

    QPainter painter(&star);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QRgb(0xf6a625));
    painter.setBrush(painter.pen().color());
    painter.drawPath(starPath);

    return std::move(star);
}

inline static void setBrush(QScatterSeries * arg) {
    static auto const varBrushImage = getBrushFileName();
    arg->setBrush(varBrushImage);
}

ScatterSeriesHelp::ScatterSeriesHelp(QScatterSeries * arg) :
    QObject(arg), super(arg) {
}

ScatterSeriesHelp *ScatterSeriesHelp::qmlAttachedProperties(QObject *object) {
    assert(dynamic_cast<QScatterSeries *>(object));
    auto varQScatterSeries =
        reinterpret_cast<QScatterSeries *>(object);
    return sstd_new<ScatterSeriesHelp>(varQScatterSeries);
}

int ScatterSeriesHelp::getFlag() const {
    return mmmFlag;
}

void ScatterSeriesHelp::setFlag(int arg) {
    if (arg == mmmFlag) {
        return;
    }

    switch (arg) {
    case 1:
    {
        super->setMarkerShape(QScatterSeries::MarkerShapeRectangle);
        super->setMarkerSize(varMarkSize);
        super->setPen(Qt::NoPen);
        setBrush(super);
    }break;
    default:
    {
        static_assert(varMarkSize > 8);
        super->setBrush(QColor(100, 100, 252));
        super->setMarkerSize(varMarkSize - 8);
        super->setPen(QPen{ QColor(255,128,128),2 });
        super->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    }break;
    }

    mmmFlag = arg;
    flagChanged();
}

static inline void register_this() {
    qmlRegisterUncreatableType<ScatterSeriesHelp>(
        "sstd.charts.help",
        1, 0,
        "ScatterSeriesHelp",
        "can not create ...");
}
Q_COREAPP_STARTUP_FUNCTION(register_this)
























