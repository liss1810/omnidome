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
#ifndef OMNI_UI_COLLAPSIBLEGROUPBOX_H_
#define OMNI_UI_COLLAPSIBLEGROUPBOX_H_


#include <omni/util.h>
#include <QFrame>
#include <QToolButton>

namespace omni {
    namespace ui {
        class CollapsibleGroupBox : public QWidget {
            Q_OBJECT
        public:
            CollapsibleGroupBox(QWidget* _parent = nullptr);
            virtual ~CollapsibleGroupBox();

            bool isCollapsed() const;
            QWidget* widget();
            QWidget const* widget() const;

            void setWidget(QWidget*);

            QString title();
            void setTitle(QString const&);

        public slots:
            void collapse(bool = true);

        signals:
            void collapsed(bool);

        private:
            QWidget* widget_;
            QToolButton* button_;
        };
    }
}

#endif /* OMNI_UI_COLLAPSIBLEGROUPBOX_H_ */
