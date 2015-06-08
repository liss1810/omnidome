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

      void initializeGL();

    public slots:
      void changeZoom(int _value);

    protected:
      void paintGL();

      void wheelEvent(QWheelEvent* event);
      void keyPressEvent(QKeyEvent* event);
      void mouseMoveEvent(QMouseEvent *event);
 
    private:
      void initialize();

      void updateLight();

      visual::Camera camera_;
      std::array<visual::Light,3> lights_;
    };
  }
}

#endif /* OMNI_UI_GLVIEW3D_H_ */