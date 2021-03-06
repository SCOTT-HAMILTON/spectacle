/* This file is part of Spectacle, the KDE screenshot utility
 * Copyright (C) 2015 Boudhayan Gupta <bgupta@kde.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once

#include <QLabel>
#include <QMouseEvent>
#include <QPoint>
#include <QPixmap>
#include <QGraphicsDropShadowEffect>


namespace SpectacleImage {
    static const int SHADOW_RADIUS = 5;
}

class KSImageWidget : public QLabel
{
    Q_OBJECT


    public:

    explicit KSImageWidget(QWidget *parent = nullptr);
    void setScreenshot(const QPixmap &pixmap);

    Q_SIGNALS:

    void dragInitiated();

    protected:

    void mousePressEvent(QMouseEvent *event)   override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event)    override;
    void resizeEvent(QResizeEvent *event)      override;

    private:

    void setScaledPixmap();

    QGraphicsDropShadowEffect *mDSEffect;
    QPixmap                    mPixmap;
    QPoint                     mDragStartPosition;
};
