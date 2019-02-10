﻿/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtGui module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or (at your option) the GNU General
** Public license version 3 or any later version approved by the KDE Free
** Qt Foundation. The licenses are as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-2.0.html and
** https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#pragma once

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtGui/private/qtguiglobal_p.h>
#include <QtGui/qabstracttextdocumentlayout.h>
#include <QtGui/qtextoption.h>
#include <QtGui/qtextobject.h>

QT_BEGIN_NAMESPACE

class QTextListFormat;
class QTextTableCell;
class QTextDocumentLayoutPrivate;

class QTextDocumentLayout : public QAbstractTextDocumentLayout
{
    Q_DECLARE_PRIVATE(QTextDocumentLayout)
    Q_OBJECT
    Q_PROPERTY(int cursorWidth READ cursorWidth WRITE setCursorWidth)
    Q_PROPERTY(qreal idealWidth READ idealWidth)
    Q_PROPERTY(bool contentHasAlignment READ contentHasAlignment)
public:
    inline explicit QTextDocumentLayout(QTextDocument *doc);

    // from the abstract layout
    inline void draw(QPainter *painter, const PaintContext &context) override;
    inline int hitTest(const QPointF &point, Qt::HitTestAccuracy accuracy) const override;

    inline int pageCount() const override;
    inline QSizeF documentSize() const override;

    inline void setCursorWidth(int width);
    inline int cursorWidth() const;

    // internal, to support the ugly FixedColumnWidth wordwrap mode in QTextEdit
    inline void setFixedColumnWidth(int width);

    // internal for QTextEdit's NoWrap mode
    inline void setViewport(const QRectF &viewport);

    inline virtual QRectF frameBoundingRect(QTextFrame *frame) const override;
    inline virtual QRectF blockBoundingRect(const QTextBlock &block) const override;
    inline QRectF tableBoundingRect(QTextTable *table) const;
    inline QRectF tableCellBoundingRect(QTextTable *table, const QTextTableCell &cell) const;

    // ####
    inline int layoutStatus() const;
    inline int dynamicPageCount() const;
    inline QSizeF dynamicDocumentSize() const;
    inline void ensureLayouted(qreal);

    inline qreal idealWidth() const;

    inline bool contentHasAlignment() const;

protected:
    inline void documentChanged(int from, int oldLength, int length) override;
    inline void resizeInlineObject(QTextInlineObject item, int posInDocument, const QTextFormat &format) override;
    inline void positionInlineObject(QTextInlineObject item, int posInDocument, const QTextFormat &format) override;
    inline void drawInlineObject(QPainter *p, const QRectF &rect, QTextInlineObject item,
                          int posInDocument, const QTextFormat &format) override;
    inline virtual void timerEvent(QTimerEvent *e) override;
private:
    inline QRectF doLayout(int from, int oldLength, int length);
    inline void layoutFinished();
};

QT_END_NAMESPACE

#ifndef QT_NO_CSSPARSER
#define QT_NO_CSSPARSER 1
#endif

#ifdef CHAT_VIEW_LEFT_LIBRARY
#include "left_qtextdocumentlayout.hpp"
#endif

