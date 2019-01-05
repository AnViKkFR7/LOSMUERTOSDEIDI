#define GLM_FORCE_RADIANS
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLWidget>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QKeyEvent>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "model.h"
class MyGLWidget : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core
{
  Q_OBJECT

  public:
    MyGLWidget (QWidget *parent=0);
    ~MyGLWidget ();

  protected:
    // initializeGL - Aqui incluim les inicialitzacions del contexte grafic.
    virtual void initializeGL ( );
    // paintGL - Mètode cridat cada cop que cal refrescar la finestra.
    // Tot el que es dibuixa es dibuixa aqui.
    virtual void paintGL ( );
    // resizeGL - És cridat quan canvia la mida del widget
    virtual void resizeGL (int width, int height);
    // keyPressEvent - Es cridat quan es prem una tecla
    virtual void keyPressEvent (QKeyEvent *event);

  private:
    void createBuffersModel();
    void createBuffersTerra();
    void carregaShaders ();
    void modelTransformHomer();
    void modelTransformTerra();
    void modelTransformPatricio();
    void projectTransform();
    void viewTransform();
    void iniCamera();
    glm::vec3 calculCapsaContenidora();
    void calculaCapsaModel();
    void cameraDe1a4();

    // attribute locations
    GLuint vertexLoc, colorLoc;
    // uniform locations
    GLuint transLoc, projLoc, viewLoc;
    // VAO names
    GLuint VAO_Hom, VAO_Terra, VAO_Patr;
    //GLuint VAO_Terra;
    // Program
    QOpenGLShaderProgram *program;
    // Internal vars
    Model hom, patr;
    bool esPrimera;

    glm::vec3 centreBaseHom;
    glm::vec3 centreBasePatr;
    float scale, rot, escala;
    glm::vec3 pos, VRP, OBS, UP, up, pmin, pmax;
    float FOV, ra, znear, zfar, R, d, psi, theta, alphaInicial;
};
