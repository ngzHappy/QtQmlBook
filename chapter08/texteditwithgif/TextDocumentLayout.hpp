#pragma once

#include <sstd_qt_and_qml_library.hpp>
#include <QtGui/private/qtextdocumentlayout_p.h>

class TextQmlWrappedItem {
    const QString mmmQmlPath;
    const int mmmImageWidth;
    const int mmmImageHeight;
    double mmmX{ 0 };
    double mmmY{ 0 };
    QQuickItem * mmmItem{nullptr};
    QPointer< QQuickItem > mmmWatcher;
    bool mmmNeedUpdatePos{true};
public:
    TextQmlWrappedItem(const QString &,int,int);
    ~TextQmlWrappedItem();

    double getX() const;
    double getY() const;
    void setX(double);
    void setY(double);
    double getWidth() const;
    double getHeight() const;
    QString getQmlPathName() const;
    bool needUpdatePos() const;
    void setNeedUpdatePos(bool);

    inline void setItem(QQuickItem * arg) {
        assert(mmmItem==nullptr);
        mmmItem = arg;
        mmmWatcher = arg;
    }

    inline QQuickItem * getItem() const {
        return mmmItem;
    }

    inline void releaseItem() {
        auto varItem = mmmWatcher.data();
        mmmItem = nullptr;
        mmmWatcher.clear();
        if (varItem) {
            delete varItem;
        }
    }

private:
    SSTD_DEFINE_STATIC_CLASS(TextQmlWrappedItem);
};

class TextDocumentLayout :
    public QTextDocumentLayout,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(TextDocumentLayout) {
private:
    Q_OBJECT
private:
    using Super = QTextDocumentLayout;
public:
    TextDocumentLayout(QTextDocument *);
    using QmlItems = sstd::map<
        int,
        std::shared_ptr< TextQmlWrappedItem  >
    >;
    inline const QmlItems & getQmlItems() const;
private:
    void updateQmlPos(QTextInlineObject item, int posInDocument, const QTextFormat &format);
protected:
    void positionInlineObject(QTextInlineObject item, int posInDocument, const QTextFormat &format) override;
    void resizeInlineObject(QTextInlineObject item, int posInDocument, const QTextFormat &format) override;
    void documentChanged(int position, int charsRemoved, int charsAdded) override;
private:
    sstd::map< 
        int, 
        std::shared_ptr< TextQmlWrappedItem  > 
    > mmmQmlItems;
    qreal mmmPageWidth{0};
    QTextDocument * mmmDocument{ nullptr };
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(TextDocumentLayout);
};

inline const TextDocumentLayout::QmlItems & TextDocumentLayout::getQmlItems() const {
    return mmmQmlItems;
}


















