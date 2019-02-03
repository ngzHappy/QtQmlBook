#include "ScatterSeriesHelp.hpp"

constexpr const auto static varPI = 3.141592654;
constexpr const auto static varMarkSize = 32;

inline static QString getBrushFileName() {
    QPainterPath starPath;
    starPath.moveTo(28, 15);
    for (int i = 1; i < 5; ++i) {
        starPath.lineTo(14 + 14 * qCos(0.8 * i * varPI),
            15 + 14 * qSin(0.8 * i * varPI));
    }
    starPath.closeSubpath();

    QImage star(varMarkSize, varMarkSize, QImage::Format_ARGB32);
    star.fill(Qt::transparent);

    QPainter painter(&star);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QRgb(0xf6a625));
    painter.setBrush(painter.pen().color());
    painter.drawPath(starPath);

    QDir varDir{ qApp->applicationDirPath() };
    varDir.mkpath(
        varDir.absoluteFilePath(QStringLiteral("myImages")));
    auto varSaveFileName =
        varDir.absoluteFilePath(QStringLiteral("myImages/star_brush.png"));
    star.save(varSaveFileName);
    return varSaveFileName;
}

inline static void setBrushFilename(QScatterSeries * arg) {
    static auto const varBrushFileName = getBrushFileName();
    arg->setProperty("brushFilename", varBrushFileName);
}


ScatterSeriesHelp::ScatterSeriesHelp(QScatterSeries * arg) :
    QObject(arg) {
    arg->setBorderColor(QColor(123, 123, 100, 255));
    arg->setMarkerShape(QScatterSeries::MarkerShapeRectangle);
    arg->setMarkerSize(varMarkSize);
    setBrushFilename(arg);
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
























