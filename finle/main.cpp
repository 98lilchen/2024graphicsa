///先把 week08-1_glm_gundam 的程式貼上來
///等一下, 要再加貼圖的 18行程式
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
#include <GL/glut.h>
#include "glm.h"
float teapotX=0, teapotY=0;

GLMmodel * body = NULL;
GLMmodel * breast = NULL;
GLMmodel * headlower = NULL;
GLMmodel * headm = NULL;
GLMmodel * headupper = NULL;
GLMmodel * lefthand = NULL;
GLMmodel * leftleg = NULL;
GLMmodel * leftmhand = NULL;
GLMmodel * leftmleg = NULL;
GLMmodel * leftupperhand = NULL;
GLMmodel * leftupperleg = NULL;
GLMmodel * righthand = NULL;
GLMmodel * rightleg = NULL;
GLMmodel * rightmhand = NULL;
GLMmodel * rightmleg = NULL;
GLMmodel * rightupperhand = NULL;
GLMmodel * rightupperleg = NULL;
GLMmodel * waist = NULL;
GLMmodel * waistlower = NULL;

void drawbody(void)
{
    if (!body) {
	body = glmReadOBJ("data/body.obj");
	if (!body) exit(0);
	glmUnitize(body);
	glmFacetNormals(body);
	glmVertexNormals(body, 90.0);
    }

    glmDraw(body, GLM_SMOOTH | GLM_TEXTURE);
}

void drawbreast(void)
{
    if (!breast) {
	breast = glmReadOBJ("data/breast.obj");
	if (!breast) exit(0);
	glmUnitize(breast);
	glmFacetNormals(breast);
	glmVertexNormals(breast, 90.0);
    }

    glmDraw(breast, GLM_SMOOTH | GLM_TEXTURE);
}

void drawheadlower(void)
{
    if (!headlower) {
	headlower = glmReadOBJ("data/headlower.obj");
	if (!headlower) exit(0);
	glmUnitize(headlower);
	glmFacetNormals(headlower);
	glmVertexNormals(headlower, 90.0);
    }

    glmDraw(headlower, GLM_SMOOTH | GLM_TEXTURE);
}

void drawheadm(void)
{
    if (!headm) {
	headm = glmReadOBJ("data/headm.obj");
	if (!headm) exit(0);
	glmUnitize(headm);
	glmFacetNormals(headm);
	glmVertexNormals(headm, 90.0);
    }

    glmDraw(headm, GLM_SMOOTH | GLM_TEXTURE);
}

void drawheadupper(void)
{
    if (!headupper) {
	headupper = glmReadOBJ("data/headupper.obj");
	if (!headupper) exit(0);
	glmUnitize(headupper);
	glmFacetNormals(headupper);
	glmVertexNormals(headupper, 90.0);
    }

    glmDraw(headupper, GLM_SMOOTH | GLM_TEXTURE);
}

void drawlefthand(void)
{
    if (!lefthand) {
	lefthand = glmReadOBJ("data/lefthand.obj");
	if (!lefthand) exit(0);
	glmUnitize(lefthand);
	glmFacetNormals(lefthand);
	glmVertexNormals(lefthand, 90.0);
    }

    glmDraw(lefthand, GLM_SMOOTH | GLM_TEXTURE);
}

void drawleftleg(void)
{
    if (!leftleg) {
	leftleg = glmReadOBJ("data/leftleg.obj");
	if (!leftleg) exit(0);
	glmUnitize(leftleg);
	glmFacetNormals(leftleg);
	glmVertexNormals(leftleg, 90.0);
    }

    glmDraw(leftleg, GLM_SMOOTH | GLM_TEXTURE);
}

void drawleftmhand(void)
{
    if (!leftmhand) {
	leftmhand = glmReadOBJ("data/leftmhand.obj");
	if (!leftmhand) exit(0);
	glmUnitize(leftmhand);
	glmFacetNormals(leftmhand);
	glmVertexNormals(leftmhand, 90.0);
    }

    glmDraw(leftmhand, GLM_SMOOTH | GLM_TEXTURE);
}

void drawleftmleg(void)
{
    if (!leftmleg) {
	leftmleg = glmReadOBJ("data/leftmleg.obj");
	if (!leftmleg) exit(0);
	glmUnitize(leftmleg);
	glmFacetNormals(leftmleg);
	glmVertexNormals(leftmleg, 90.0);
    }

    glmDraw(leftmleg, GLM_SMOOTH | GLM_TEXTURE);
}

void drawleftupperhand(void)
{
    if (!leftupperhand) {
	leftupperhand = glmReadOBJ("data/leftupperhand.obj");
	if (!leftupperhand) exit(0);
	glmUnitize(leftupperhand);
	glmFacetNormals(leftupperhand);
	glmVertexNormals(leftupperhand, 90.0);
    }

    glmDraw(leftupperhand, GLM_SMOOTH | GLM_TEXTURE);
}

void drawleftupperleg(void)
{
    if (!leftupperleg) {
	leftupperleg = glmReadOBJ("data/leftupperleg.obj");
	if (!leftupperleg) exit(0);
	glmUnitize(leftupperleg);
	glmFacetNormals(leftupperleg);
	glmVertexNormals(leftupperleg, 90.0);
    }

    glmDraw(leftupperleg, GLM_SMOOTH | GLM_TEXTURE);
}

void drawrighthand(void)
{
    if (!righthand) {
	righthand = glmReadOBJ("data/righthand.obj");
	if (!righthand) exit(0);
	glmUnitize(righthand);
	glmFacetNormals(righthand);
	glmVertexNormals(righthand, 90.0);
    }

    glmDraw(righthand, GLM_SMOOTH | GLM_TEXTURE);
}

void drawrightleg(void)
{
    if (!rightleg) {
	rightleg = glmReadOBJ("data/rightleg.obj");
	if (!rightleg) exit(0);
	glmUnitize(rightleg);
	glmFacetNormals(rightleg);
	glmVertexNormals(rightleg, 90.0);
    }

    glmDraw(rightleg, GLM_SMOOTH | GLM_TEXTURE);
}

void drawrightmhand(void)
{
    if (!rightmhand) {
	rightmhand = glmReadOBJ("data/rightmhand.obj");
	if (!rightmhand) exit(0);
	glmUnitize(rightmhand);
	glmFacetNormals(rightmhand);
	glmVertexNormals(rightmhand, 90.0);
    }

    glmDraw(rightmhand, GLM_SMOOTH | GLM_TEXTURE);
}

void drawrightmleg(void)
{
    if (!rightmleg) {
	rightmleg = glmReadOBJ("data/rightmleg.obj");
	if (!rightmleg) exit(0);
	glmUnitize(rightmleg);
	glmFacetNormals(rightmleg);
	glmVertexNormals(rightmleg, 90.0);
    }

    glmDraw(rightmleg, GLM_SMOOTH | GLM_TEXTURE);
}

void drawrightupperhand(void)
{
    if (!rightupperhand) {
	rightupperhand = glmReadOBJ("data/rightupperhand.obj");
	if (!rightupperhand) exit(0);
	glmUnitize(rightupperhand);
	glmFacetNormals(rightupperhand);
	glmVertexNormals(rightupperhand, 90.0);
    }

    glmDraw(rightupperhand, GLM_SMOOTH | GLM_TEXTURE);
}

void drawrightupperleg(void)
{
    if (!rightupperleg) {
	rightupperleg = glmReadOBJ("data/rightupperleg.obj");
	if (!rightupperleg) exit(0);
	glmUnitize(rightupperleg);
	glmFacetNormals(rightupperleg);
	glmVertexNormals(rightupperleg, 90.0);
    }

    glmDraw(rightupperleg, GLM_SMOOTH | GLM_TEXTURE);
}

void drawwaist(void)
{
    if (!waist) {
	waist = glmReadOBJ("data/waist.obj");
	if (!waist) exit(0);
	glmUnitize(waist);
	glmFacetNormals(waist);
	glmVertexNormals(waist, 90.0);
    }

    glmDraw(waist, GLM_SMOOTH | GLM_TEXTURE);
}

void drawwaistlower(void)
{
    if (!waistlower) {
	waistlower = glmReadOBJ("data/waistlower.obj");
	if (!waistlower) exit(0);
	glmUnitize(waistlower);
	glmFacetNormals(waistlower);
	glmVertexNormals(waistlower, 90.0);
    }

    glmDraw(waistlower, GLM_SMOOTH | GLM_TEXTURE);
}

///float angle = 0, da=1; ///加這行, 讓它轉動
///float angle[20] = {};
float angle[20]={};
int angleID = 0;
int oldX = 0, oldY = 0;
#include <stdio.h>
FILE * fin = NULL;
FILE * fout = NULL;
void motion(int x,int y)
{
    if(1){
        teapotX += (x- oldX)/150.0;
        teapotY -= (y- oldY)/150.0;
        printf("glTranslatef(%.3f, %.3f,0);\n",teapotX,teapotY);
    }else {
        angle[angleID]+=y-oldY;
    }
    oldX = x;
    oldY = y;
    glutPostRedisplay();

}
void mouse(int button, int state, int x, int y)
{
    oldX = x;
    oldY = y;
}
float oldAngleX[10] = {}, newAngleX[10] = {};
float oldAngleY[10] = {}, newAngleY[10] = {};
void timer(int t)
{
    glutTimerFunc(50,timer,t+1);
    if(t%20==0)
    {
        if(fin==NULL) fin = fopen("angle.txt","r");
        for(int i=0;i<10;i++)
        {
            oldAngleX[i] = newAngleX[i];
            oldAngleY[i] = newAngleY[i];
            fscanf(fin, "%f", & newAngleX[i] );
            fscanf(fin, "%f", & newAngleY[i] );
        }
    }
    float alpha = (t%20) / 20.0;
    for(int i=0;i<10;i++)
    {
        angleX[i] = newAngleX[i]*alpha + oldAngleX[i]*(1-alpha);
        angleY[i] = newAngleY[i]*alpha + oldAngleY[i]*(1-alpha);
    }
    glutPostRedisplay();
}
void keyboard(unsigned char key, int x, int y)
{
    if(key=='p')
    {
        glutTimerFunc(0,timer,0);
    }
    if(key=='r')
    {
        if(fin==NULL) fin = fopen("angle.txt","r");
        for(int i=0;i<10;i++)
        {
            fscanf(fin, "%f", &angleX[i]);
            fscanf(fin, "%f", &angleY[i]);
        }
        glutPostRedisplay();
    }
    else if(key=='s')
    {
        if(fout==NULL) fout = fopen("angle.txt", "w+");
        for(int i=0; i<10; i++)
            {
                printf("%.1f ",angleX[i]);
                printf("%.1f ",angleY[i]);
                fprintf(fout, "%.1f ",angleX[i]);
                fprintf(fout, "%.1f ",angleY[i]);
            }
            printf("\n");
            fprintf(fout, "\n");
    }
    if(key=='0') angleID = 0;
    if(key=='1') angleID = 1;
    if(key=='2') angleID = 2;
    if(key=='3') angleID = 3;
    if(key=='4') angleID = 4;
    if(key=='5') angleID = 5;
    if(key=='6') angleID = 6;
    if(key=='7') angleID = 7;
    if(key=='8') angleID = 8;
    if(key=='9') angleID = 9;
}
void display()
{

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glDisable(GL_TEXTURE_2D);
    glutSolidSphere(0.02,30,30);

    glPushMatrix();
        drawbody();
    glPopMatrix();

    glutSwapBuffers();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };///加這行, 讓它轉動

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };


int main(int argc, char*argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week13-1");
    glutDisplayFunc(display);
    glutIdleFunc(display); ///加這行, 讓它轉動
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);
    ///glutTimerFunc(0,timer,0);

    ///myTexture("data/Diffuse.jpg");

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();
}
