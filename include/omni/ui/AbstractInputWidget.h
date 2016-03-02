/* Copyright (c) 2014-2015 "Omnidome" by cr8tr
 * Dome Mapping Projection Software (http://omnido.me).
 * Omnidome was created by Michael Winkelmann aka Wilston Oreo (@WilstonOreo)
 *
 * This file is part of Omnidome.
 *
 * Omnidome is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef OMNI_UI_ABSTRACTINPUTWIDGET_H_
#define OMNI_UI_ABSTRACTINPUTWIDGET_H_

#include <QLayout>
#include <omni/ui/mixin/Editor.h>
#include "Widget.h"

namespace omni
{
        namespace ui
        {
                class AbstractInputWidget :
                    public Widget,
                    protected mixin::Editor<AbstractInputWidget,QWidget>
                {
                        Q_OBJECT
                    public:
                        typedef mixin::Editor<AbstractInputWidget,QWidget> mixin_editor_type;
                        AbstractInputWidget(QWidget* = nullptr);
                        virtual ~AbstractInputWidget() {
                        }

                    public slots:
                        virtual void setEditorVisible(bool);
                        void showEditor();
                        void hideEditor();

                    signals:
                        void valueChanged();

                    protected:
                        virtual void mouseDoubleClickEvent(QMouseEvent*);
                        virtual void mousePressEvent(QMouseEvent*);
                        virtual void keyPressEvent(QKeyEvent*);

                        void drawHandle(QPainter& _p, double _pos, double _heightFactor = 1.0) const;

                        void drawTrack(QPainter& _p, double _pos) const;

                        void drawTrack(QPainter& _p, double _left, double _right) const;

                        void init();

                        QLabel* valueLabel_ = nullptr;
                };
        }
}

#endif /* OMNI_UI_ABSTRACTINPUTWIDGET_H_ */