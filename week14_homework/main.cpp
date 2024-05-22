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
GLMmodel * pmodel = NULL;
GLMmodel * righthand = NULL;
GLMmodel * rightleg = NULL;
GLMmodel * rightupper = NULL;
GLMmodel * rightMhand = NULL;
GLMmodel * leftleg = NULL;
GLMmodel * lefthand = NULL;
GLMmodel * leftMhand = NULL;
GLMmodel * leftupper = NULL;
GLMmodel * head = NULL;
GLMmodel * body = NULL;
void drawBody(void)
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

void drawmodle(void)
{
    if (!pmodel) {
	pmodel = glmReadOBJ("data/Gundam.obj");
	if (!pmodel) exit(0);
	glmUnitize(pmodel);
	glmFacetNormals(pmodel);
	glmVertexNormals(pmodel, 90.0);
    }

    glmDraw(pmodel, GLM_SMOOTH | GLM_TEXTURE);
}

void drawLeftHand(void)
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

void drawRightHand(void)
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

void drawRightLeg(void)
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

void drawRightMHand(void)
{
    if (!rightMhand) {
	rightMhand = glmReadOBJ("data/rightMhand.obj");
	if (!rightMhand) exit(0);
	glmUnitize(rightMhand);
	glmFacetNormals(rightMhand);
	glmVertexNormals(rightMhand, 90.0);
    }

    glmDraw(rightMhand, GLM_SMOOTH | GLM_TEXTURE);
}

void drawRightUpper(void)
{
    if (!rightupper) {
	rightupper = glmReadOBJ("data/rightupper.obj");
	if (!rightupper) exit(0);
	glmUnitize(rightupper);
	glmFacetNormals(rightupper);
	glmVertexNormals(rightupper, 90.0);
    }

    glmDraw(rightupper, GLM_SMOOTH | GLM_TEXTURE);
}

void drawLeftLeg(void)
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

void drawLeftMHand(void)
{
    if (!leftMhand) {
	leftMhand = glmReadOBJ("data/leftMhand.obj");
	if (!leftMhand) exit(0);
	glmUnitize(leftMhand);
	glmFacetNormals(leftMhand);
	glmVertexNormals(leftMhand, 90.0);
    }

    glmDraw(leftMhand, GLM_SMOOTH | GLM_TEXTURE);
}

void drawLeftUpper(void)
{
    if (!leftupper) {
	leftupper = glmReadOBJ("data/leftupper.obj");
	if (!leftupper) exit(0);
	glmUnitize(leftupper);
	glmFacetNormals(leftupper);
	glmVertexNormals(leftupper, 90.0);
    }

    glmDraw(leftupper, GLM_SMOOTH | GLM_TEXTURE);
}

void drawHead(void)
{
    if (!head) {
	head = glmReadOBJ("data/head.obj");
	if (!head) exit(0);
	glmUnitize(head);
	glmFacetNormals(head);
	glmVertexNormals(head, 90.0);
    }

    glmDraw(head, GLM_SMOOTH | GLM_TEXTURE);
}
void myBody(){
    glPushMatrix();
    glColor3f(1,0,0);
    glutSolidCube(0.6);
    glPopMatrix();
}
///float angle = 0, da=1; ///加這行, 讓它轉動
float angle[20] = {};
int angleID = 0;
int oldX = 0, oldY = 0;
#include <stdio.h>
FILE * fin = NULL;
FILE * fout = NULL;
void motion(int x,int y)
{
    angle[angleID] += y-oldY;
    oldX = x;
    oldY = y;
    glutPostRedisplay();
    if(fout==NULL) fout = fopen("angle.txt", "w+");
    for(int i=0; i<20; i++)
    {
        printf("%.1f ",angle[i]);
        fprintf(fout, "%.1f ",angle[i]);
    }
    printf("\n");
    fprintf(fout, "\n");
}
void mouse(int button, int state, int x, int y)
{
    oldX = x;
    oldY = y;
}
void keyboard(unsigned char key, int x, int y)
{
    if(key=='r')
    {
        if(fin==NULL) fin = fopen("angle.txt","r");
        for(int i=0;i<20;i++)
        {
            fscanf(fin, "%f", &angle[i]);
        }
        glutPostRedisplay();
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
    ///angle+=da;
    ///if(angle>90) da= -1;
    ///if(angle<0) da= +1;
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glDisable(GL_TEXTURE_2D);
    glPushMatrix();
    glRotatef(angle[0],0,1,0);
    drawBody();
    ///glutSolidSphere(0.1,30,30);
    glEnable(GL_TEXTURE_2D);
    glColor3f(1,1,1);

    glPushMatrix();
        glTranslatef(-0.1,0,0);
        glRotatef(angle[1],0,0,1);
        glRotatef(angle[2],1,0,0);
        glRotatef(angle[4],0,1,0);
        glRotatef(angle[5],1,0,0);
        glRotatef(angle[6],1,0,0);
        glRotatef(angle[7],1,0,0);
        glRotatef(angle[8],1,0,0);
        glRotatef(angle[9],1,0,0);
        glTranslatef(0,-0.07,0);
        drawRightHand();
        glPushMatrix();
            glTranslatef(-0.02,-0.09,0);
            glRotatef(angle[3],1,0,0);
            glTranslatef(0,-0.21,0);
            drawLeftHand();
        glPopMatrix();
    glPopMatrix();

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

    myTexture("data/Diffuse.jpg");

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
