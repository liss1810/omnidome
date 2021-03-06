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

#include "Box.h"
#include "BoxWidget.h"

namespace omni {
    namespace ui {
        namespace canvas {
            Box::Box(QWidget *_parent) : CanvasParameters(_parent) {
                setup();
            }

            Box::Box(omni::canvas::Interface *_canvas, QWidget *_parent) :
                CanvasParameters(_canvas, _parent) {
                setup();
            }

            Box::~Box() {}

            void Box::updateCanvasParameters() {
                auto *_box = static_cast<omni::canvas::Box *>(canvas());

                _box->setSize(QVector3D(
                                  getParamAsFloat("Width"),
                                  getParamAsFloat("Length"),
                                  getParamAsFloat("Height")
                                  ));
            }

            void Box::setup() {
                if (!canvas()) return;

                this->locked([&]() {
                    auto *_height = addOffsetWidget("Height", 1.0, 0.1, 10.0);
                    auto *_length = addOffsetWidget("Length", 1.0, 0.1, 10.0);
                    auto *_width = addOffsetWidget("Width", 1.0, 0.1, 10.0);
                    auto *_xOffset = addOffsetWidget("X Offset",
                                                     0.0,
                                                     -10.0,
                                                     10.0);
                    auto *_yOffset = addOffsetWidget("Y Offset",
                                                     0.0,
                                                     -10.0,
                                                     10.0);
                    auto *_zOffset = addOffsetWidget("Z Offset",
                                                     0.0,
                                                     -10.0,
                                                     10.0);

                    /// Retrieve parameters for Box canvas
                    auto *_box = static_cast<omni::canvas::Box *>(canvas());
                    _width->setValue(_box->size().x());
                    _length->setValue(_box->size().y());
                    _height->setValue(_box->size().z());
                    _xOffset->setValue(_box->center().x());
                    _yOffset->setValue(_box->center().y());
                    _zOffset->setValue(_box->center().z());
                });
            }
        }
    }
}
