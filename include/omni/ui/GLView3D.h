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

#ifndef OMNI_UI_GLVIEW3D_H_
#define OMNI_UI_GLVIEW3D_H_

#include <omni/ui/GLView.h>
#include <omni/visual/Camera.h>
#include <omni/visual/Light.h>

namespace omni
{
  namespace ui
  {
    /**@brief An OpenGL view with a camera and perspective view
     * @detail Also holds three lights
     **/
    class GLView3D : public GLView
    {
      Q_OBJECT
    public:
      GLView3D(QWidget* _parent = nullptr);
      ~GLView3D();

      bool displayInput() const;
      ProjectorViewMode projectorViewMode() const;

    public slots:
      void setDisplayInput(bool);
      void setProjectorViewMode(ProjectorViewMode);
      void changeZoom(int _value);

    protected:
      virtual void paintGL();

      virtual void wheelEvent(QWheelEvent* event);
      virtual void keyPressEvent(QKeyEvent* event);
      virtual void mouseMoveEvent(QMouseEvent *event);

      void setupCamera();
      void updateLight();

    private:
      bool initialize();

      visual::Camera camera_;
      std::array<visual::Light,3> lights_;
      bool displayInput_ = true;
      ProjectorViewMode projectorViewMode_ = ProjectorViewMode::INSIDE;
    };
  }
}

#endif /* OMNI_UI_GLVIEW3D_H_ */
