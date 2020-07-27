
#include<windows.h>
#include <gl/glut.h>
#include<math.h>

void init(void);
void tampil(void);
void display(void);
void posenggggg(void);
void Lapangan(void);
void lawang(void);
void Penonton(void);
void atap(void);
void awan(void);
//void lingkaran(void);
void mouse(int button, int state, int x, int y);
void keyboard(unsigned char, int, int);
void ukuran(int, int);
void mouseMotion(int x, int y);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;
int sudut=0, o=0, p=0, q=0;
int i=0; int j=0;


void awan(void){
    glEnable(GL_LIGHTING);
     glPushMatrix();
     glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
     glColor3ub(153, 223, 255);
     glPopMatrix();
     glPushMatrix();
     glTranslatef(0,0,200);
     glutSolidSphere(10, 50, 50);
     glPopMatrix();
     glPushMatrix();
     glTranslatef(10,0,200);
     glutSolidSphere(5, 50, 50);
     glPopMatrix();
     glPushMatrix();
     glTranslatef(-2,6,200);
     glutSolidSphere(7, 50, 50);
     glPopMatrix();
     glPushMatrix();
     glTranslatef(-10,-3,200);
     glutSolidSphere(7, 50, 50);
     glPopMatrix();
     glPushMatrix();
     glTranslatef(6,-2,205);
     glutSolidSphere(7, 50, 50);
     glPopMatrix();

     //

     glPushMatrix();
     glColor3ub(153, 223, 255);
     glPopMatrix();
     glPushMatrix();
     glTranslatef(50,50,200);
     glutSolidSphere(10, 50, 50);
     glPopMatrix();
     glPushMatrix();
     glTranslatef(60,50,200);
     glutSolidSphere(5, 50, 50);
     glPopMatrix();
     glPushMatrix();
     glTranslatef(48,56,200);
     glutSolidSphere(7, 50, 50);
     glPopMatrix();
     glPushMatrix();
     glTranslatef(40,47,200);
     glutSolidSphere(7, 50, 50);
     glPopMatrix();
     glPushMatrix();
     glTranslatef(56,48,205);
     glutSolidSphere(7, 50, 50);
     glPopMatrix();

    glDisable(GL_LIGHTING);
 }

void nGon(int n, float cx, float cy, float radius, float rotAngle)
{
    double angle, angleInc;
    int k;
    if(n < 3 )return;
    angle = rotAngle * 3.14159265 /90;
    angleInc = 2 * 3.14159265/n;
    glVertex2f(radius * cos(angle) + cx, radius * sin(angle)+cy);
    for(k = 0; k < n; k++)
    {

    angle += angleInc;
    glVertex2f(radius * cos(angle) + cx, radius *sin(angle)+cy);
    }
}

int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(250, 80);

    gluOrtho2D(-320.,320.,-240.,240.);

    glutCreateWindow("By Anonymous");
    init();

    GLfloat lightpos[] = {.5, 1., 1., 0.};
    glLightfv(GL_LIGHT0, GL_POSITION, lightpos);

    glutDisplayFunc(display);
    glViewport(50,50,1200,600);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutReshapeFunc(ukuran);
    glutMainLoop();
    return 0;
}

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
    glLineWidth(1.5f);
}


void tampil(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    lingkaran();
    Lapangan();
    Penonton();
    lawang();
    atap();
    awan();
    glPushMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
void hilang(void)
{
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    Penonton();
    Lapangan();
    lawang();
    //atap();
    glPushMatrix();
    glPopMatrix();
    glutSwapBuffers();
}

//void lingkaran(int xp, int yp, int r, int n){
//    float a,x,y;
//    glBegin(GL_POLYGON);
//        a=6.28/n;
//        for (int i=0; i<n; i++){
//            x = xp+r * cos(i*a);
//            y = yp+r * sin(i*a);
//            glVertex2d(x,y);
//        }
//    glEnd();
//}

void Lapangan(void){

    //Base
	glBegin(GL_QUADS);
	glNormal3d(0.5,1.0,0);
	glColor3d(0.5,1.0,0);
	glVertex3d(-100,-64,-0.9);
	glVertex3d(-100,64,-0.9);
	glVertex3d(100,64,-0.9);
    glVertex3d(100,-64,-0.9);
    glEnd();
    //pager
    glBegin(GL_POLYGON);
	glColor3f(0.7,0.7,0.7);
	glVertex3f(-100,-64,10);
	glVertex3f(-100,64,10);
	glVertex3f(-100,64,-0.9);
    glVertex3f(-100,-64,-0.9);
    glEnd();
        glBegin(GL_POLYGON);
	glColor3f(0.7,0.7,0.7);
	glVertex3f(100,-64,10);
	glVertex3f(100,64,10);
	glVertex3f(100,64,-0.9);
    glVertex3f(100,-64,-0.9);
    glEnd();
        glBegin(GL_POLYGON);
	glColor3f(0.7,0.7,0.7);
	glVertex3f(-100,64,10);
	glVertex3f(-100,64,-0.9);
	glVertex3f(100,64,-0.9);
    glVertex3f(100,64,10);
    glEnd();

    //Kolam Iwak
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,1);
    glVertex3f(55,-20,0);
    glVertex3f(65,-20,0);
    glVertex3f(65,20,0);
    glVertex3f(55,20,0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.9,0.9,1);
    glVertex3f(55,-20,0);
    glVertex3f(65,-20,0);
    glVertex3f(65,20,0);
    glVertex3f(55,20,0);
    glEnd();
    //
    glBegin(GL_POLYGON);
    glColor3f(0.9,0.9,1);
    glVertex3f(50,-25,0);
    glVertex3f(55,-20,0);
    glVertex3f(55,20,0);
    glVertex3f(50,25,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.9,0.9,1);
    glVertex3f(70,-25,0);
    glVertex3f(65,-20,0);
    glVertex3f(65,20,0);
    glVertex3f(70,25,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.9,0.9,1);
    glVertex3f(50,-25,0);
    glVertex3f(55,-20,0);
    glVertex3f(65,-20,0);
    glVertex3f(70,-25,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.9,0.9,1);
    glVertex3f(50,25,0);
    glVertex3f(55,20,0);
    glVertex3f(65,20,0);
    glVertex3f(70,25,0);
    glEnd();



    //Road Poneglyp
    glBegin(GL_POLYGON);
    glColor3f(0.85,0.7,0.7);
    glVertex3f(30,-20,0);
    glVertex3f(40,-30,0);
    glVertex3f(40,30,0);
    glVertex3f(30,20,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.85,0.7,0.7);
    glVertex3f(-30,-20,0);
    glVertex3f(-40,-30,0);
    glVertex3f(-40,30,0);
    glVertex3f(-30,20,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.85,0.7,0.7);
    glVertex3f(30,-20,0);
    glVertex3f(40,-30,0);
    glVertex3f(-40,-30,0);
    glVertex3f(-30,-20,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.85,0.7,0.7);
    glVertex3f(30,20,0);
    glVertex3f(40,30,0);
    glVertex3f(-40,30,0);
    glVertex3f(-30,20,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.85,0.7,0.7);
    glVertex3f(5,-20,0.5);
    glVertex3f(-5,-20,0.5);
    glVertex3f(-5,-70,0.5);
    glVertex3f(5,-70,0.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.85,0.7,0.7);
    glVertex3f(40,-20,0);
    glVertex3f(50,-20,0);
    glVertex3f(50,-15,0);
    glVertex3f(40,-15,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.85,0.7,0.7);
    glVertex3f(40,20,0);
    glVertex3f(50,20,0);
    glVertex3f(50,15,0);
    glVertex3f(40,15,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.85,0.7,0.7);
    glVertex3f(-40,20,0);
    glVertex3f(-50,20,0);
    glVertex3f(-50,15,0);
    glVertex3f(-40,15,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.85,0.7,0.7);
    glVertex3f(-40,-20,0);
    glVertex3f(-50,-20,0);
    glVertex3f(-50,-15,0);
    glVertex3f(-40,-15,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.85,0.7,0.7);
    glVertex3f(-50,30,0);
    glVertex3f(-90,30,0);
    glVertex3f(-90,-30,0);
    glVertex3f(-50,-30,0);
    glEnd();

    //lampu
    glBegin(GL_LINE_STRIP);
    glColor3f(0.85,1,1);
    glVertex3f(6,-31,0.5);
    glVertex3f(6,-31,5);
    glVertex3f(4.5,-29.5,5);
//    glVertex3f(-5,-70,0.5);
//    glVertex3f(5,-70,0.5);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3f(0.85,1,1);
    glVertex3f(-6,-31,0.5);
    glVertex3f(-6,-31,5);
    glVertex3f(-4.5,-29.5,5);
    glEnd();
        glBegin(GL_TRIANGLES);
    glColor3f(1,1,0);
    glVertex3f(-4.5,-29.5,1);
    glColor3f(0.85,0.7,0.7);
    glVertex3f(-4.5,-25,1);
    glVertex3f(-0,-29.5,1);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(1,1,0);
    glVertex3f(4.5,-29.5,1);
    glColor3f(0.85,0.7,0.7);
    glVertex3f(4.5,-25,1);
    glVertex3f(0,-29.5,1);
    glEnd();
    //
//    const double PI = 3.141592653589793;
//    int j, i, radius, jumlah_titik, x_tengah, y_tengah, z_tengah;
//
//    glColor3f(0.0, 0.1, 1.0);
//    glBegin(GL_POLYGON);
//    radius=30;
//    jumlah_titik=60;
//    x_tengah=-100;
//    y_tengah=-100;
////    z_tengah=1500;
//    for (i=0;i<=360;i++){
//        float sudut=i*(2*PI/jumlah_titik);
//        float x=x_tengah+radius*cos(sudut);
//        float y=y_tengah+radius*sin(sudut);
////        float z=z_tengah;
//        glVertex2f(x/5,y/5);
//        }
//    glEnd();


    //
    for(i=0; i<=8; i++){
    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    glColor3f(1,1,1);
    glVertex3f(-90+(i*5),30,0.1);
    glVertex3f(-90+(i*5),20,0.1);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3f(1,1,1);
    glVertex3f(-90+(i*5),-30,0.1);
    glVertex3f(-90+(i*5),-20,0.1);
    glEnd();
    }
    for(i=0; i<=3; i++){
        glBegin(GL_LINE_STRIP);
        glColor3f(1,1,1);
        glVertex3f(-90+(i*5),10,0.1);
        glVertex3f(-90+(i*5),-10,0.1);
        glEnd();
        glBegin(GL_LINE_STRIP);
        glColor3f(1,1,1);
        glVertex3f(-65+(i*5),10,0.1);
        glVertex3f(-65+(i*5),-10,0.1);
        glEnd();
    }
    glBegin(GL_LINE_STRIP);
    glColor3f(1,1,1);
    glVertex3f(-90,0,0.1);
    glVertex3f(-75,0,0.1);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3f(1,1,1);
    glVertex3f(-50,0,0.1);
    glVertex3f(-65,0,0.1);
    glEnd();


//    for(i=0;i<=140;i++){
//        //for(j=i; j<=140; j++){
//        glColor3f(++i*0.5,++i*0.5,++i*1);
//        glBegin(GL_QUADS);
//
//        glVertex3f(-70+(i+2),-64,10);
////        glColor3f(++i*1,++i*1,++i*1);
//        glVertex3f(-70+(i+2),-64,20);
////        glColor3f(++i*0,++i*0,++i*0);
//        glVertex3f(-69+(i+2),-64,20);
////        glColor3f(++i*1,++i*1,++i*1);
//        glVertex3f(-69+(i+2),-64,10);
//        glEnd();
//        //}
//    }

}
void Penonton(void){


    //
    glBegin(GL_POLYGON);//bottom
    glColor3f(0,0,0.3);
	glVertex3f(30,20,0);
	glVertex3f(30,-20,0);
	glVertex3f(-30,-20,0);
	glVertex3f(-30,20,0);
	glEnd();

    //Tembok belakang
    glBegin(GL_POLYGON);// Belakang kiri
    glColor3f(0,0,0.2);
	glVertex3f(-30,20,15);
	glVertex3f(-10,20,15);
	glColor3f(1,1,0.7);
	glVertex3f(-10,20,100);
	glVertex3f(-30,20,100);
	glEnd();
	glBegin(GL_POLYGON);//Belakang kanan
    glColor3f(0,0.1,0.2);
	glVertex3f(30,20,15);
	glVertex3f(10,20,15);
	glColor3f(1,1,0.7);
	glVertex3f(10,20,100);
	glVertex3f(30,20,100);
	glEnd();
    glBegin(GL_POLYGON);//jajar genjang belakang
//    glColor3f(0.85,0.85,0.97);
    glColor3f(1,1,0.7);
	glVertex3f(-30,20,100);
	glVertex3f(30,20,100);
	glColor3f(1,1,0.7);
	glVertex3f(25,20,110);
	glVertex3f(-25,20,110);
	glEnd();
    glBegin(GL_POLYGON);// belakang quads atas
//    glColor3f(0,0.1,0.2);
	glVertex3f(-25,20,110);
	glVertex3f(25,20,110);
	glColor3f(0.85,0.85,0.97);
	glVertex3f(25,20,145);
	glVertex3f(-25,20,145);
	glEnd();
	glBegin(GL_TRIANGLES);//triangle atas belakang
    glColor3f(0.85,0.85,0.97);
	glVertex3f(-25,20,145);
	glVertex3f(25,20,145);
	glColor3f(1,1,0.7);
	glVertex3f(0,20,165);
	glEnd();

	//tengah

	glBegin(GL_QUADS);// tembok tengah 1
    glColor3f(0,0.1,0.2);
	glVertex3f(-10,-20,15);
	glVertex3f(-10,20,15);
        glColor3f(0.2,0.7,0.4);
	glVertex3f(-10,20,100);
	glVertex3f(-10,-20,100);
	glEnd();
    glBegin(GL_QUADS);//tembok tengah 2
    glColor3f(0,0.1,0.2);
	glVertex3f(10,-20,15);
	glVertex3f(10,20,15);
        glColor3f(0.2,0.7,0.4);
	glVertex3f(10,20,100);
	glVertex3f(10,-20,100);
	glEnd();
	glBegin(GL_QUADS);//tengah atap
    glColor3f(0,0.1,0.2);
	glVertex3f(10,-20,95);
	glVertex3f(10,20,95);
	glColor3f(0.2,0.3,0.1);
	glVertex3f(0,20,100);
	glVertex3f(0,-20,100);
	glEnd();
    glBegin(GL_QUADS);//tengah atap
    glColor3f(0,0.1,0.2);
	glVertex3f(-10,-20,95);
	glVertex3f(-10,20,95);
	glColor3f(0.2,0.3,0.1);
	glVertex3f(0,20,100);
	glVertex3f(0,-20,100);
	glEnd();
	//penutup
    glBegin(GL_TRIANGLES);//tengah atap 1
    glColor3f(0.8,0.8,1);
	glVertex3f(10,-20,95);
	glColor3f(1,1,0.7);
	glVertex3f(10,-20,100);
//	glColor3f(0.6,0.6,1);
    glColor3f(1,1,0.7);
	glVertex3f(0,-20,100);
	glEnd();
	    glBegin(GL_TRIANGLES);//tengah atap 2
    glColor3f(0.8,0.8,1);
	glVertex3f(10,20,95);
	glColor3f(1,1,0.7);
	glVertex3f(10,20,100);
//	glColor3f(0.6,0.6,1);
	glColor3f(1,1,0.7);
	glVertex3f(0,20,100);
	glEnd();
	    glBegin(GL_TRIANGLES);//tengah atap 3
    glColor3f(0.8,0.8,1);
	glVertex3f(-10,-20,95);
	glColor3f(1,1,0.7);
	glVertex3f(-10,-20,100);
//	glColor3f(0.6,0.6,1);
	glColor3f(1,1,0.7);
	glVertex3f(0,-20,100);
	glEnd();
	    glBegin(GL_TRIANGLES);//tengah atap 4
    glColor3f(0.8,0.8,1);
	glVertex3f(-10,20,95);
	glColor3f(1,1,0.7);
	glVertex3f(-10,20,100);
	glColor3f(1,1,0.7);//glColor3f(0.6,0.6,1);
	glVertex3f(0,20,100);
	glEnd();
	//tembok kiri
    glBegin(GL_QUADS);//sisi tembok Kiri
    glColor3f(0,0.1,0.2);
	glVertex3f(-30,-20,15);
	glVertex3f(-30,20,15);
	glColor3f(1,1,0.7);
	glVertex3f(-30,20,100);
	glVertex3f(-30,-20,100);
	glEnd();
	glBegin(GL_QUADS);//sisi tembok kiri
    glColor3f(0.85,0.85,0.97);
	glVertex3f(-30,-20,100);
	glVertex3f(-30,20,100);
	glColor3f(1,1,0.7);
	glVertex3f(-25,20,110);
	glVertex3f(-25,-20,110);
	glEnd();
	glBegin(GL_QUADS);//sisi  tembok kiri
	glColor3f(0.85,0.85,0.97);
	glVertex3f(-25,-20,145);
	glVertex3f(-25,20,145);
	glColor3f(1,1,0.7);
	glVertex3f(-25,20,110);
	glVertex3f(-25,-20,110);
	glEnd();
	glBegin(GL_QUADS);//sisi tembok Kiri
    glColor3f(0.85,0.85,0.97);
	glVertex3f(-25,-20,145);
	glVertex3f(-25,20,145);
	glColor3f(1,1,0.7);
	glVertex3f(0,20,165);
	glVertex3f(0,-20,165);
	glEnd();

    //tembok kanan
    glBegin(GL_QUADS);//sisi tembok Kanan
    glColor3f(0.85,0.85,0.97);
	glVertex3f(30,-20,15);
	glVertex3f(30,20,15);
	glColor3f(1,1,0.7);
	glVertex3f(30,20,100);
	glVertex3f(30,-20,100);
	glEnd();
	glBegin(GL_QUADS);//sisi tembok Kanan
    glColor3f(0.85,0.85,0.97);
	glVertex3f(30,-20,100);
	glVertex3f(30,20,100);
	glColor3f(1,1,0.7);
	glVertex3f(25,20,110);
	glVertex3f(25,-20,110);
	glEnd();
	glBegin(GL_QUADS);//sisi tembok Kanan
    glColor3f(0,0.1,0.2);
	glVertex3f(25,-20,145);
	glVertex3f(25,20,145);
	glColor3f(1,1,0.7);
	glVertex3f(25,20,110);
	glVertex3f(25,-20,110);
	glEnd();
	glBegin(GL_QUADS);//sisi tembok Kanan
    glColor3f(0,0.1,0.2);
	glVertex3f(25,-20,145);
	glVertex3f(25,20,145);
	glColor3f(1,1,0.7);
	glVertex3f(0,20,165);
	glVertex3f(0,-20,165);
	glEnd();

	//kaki kanan
    glBegin(GL_QUADS);//kaki depan kanan
    glColor3f(0.6,0.8,0.3);
	glVertex3f(10,-20,0);
	glVertex3f(10,-20,15);
	glVertex3f(15,-20,10);
	glVertex3f(15,-20,0);
	glEnd();
	glBegin(GL_QUADS);//kaki depan kanan
    glColor3f(0.2,0.8,0.7);
	glVertex3f(10,-20,15);
	glVertex3f(15,-20,10);
	glVertex3f(25,-20,10);
	glVertex3f(30,-20,15);
	glEnd();
	glBegin(GL_QUADS);//kaki depan kanan
    glColor3f(0.6,0.8,0.3);
	glVertex3f(30,-20,15);
	glVertex3f(30,-20,0);
	glVertex3f(25,-20,0);
	glVertex3f(25,-20,10);
	glEnd();
	//
	glBegin(GL_QUADS);//kaki depan 2 kanan
    glColor3f(0.6,0.8,0.3);
	glVertex3f(10,-15,0);
	glVertex3f(10,-15,15);
	glVertex3f(15,-15,10);
	glVertex3f(15,-15,0);
	glEnd();
	glBegin(GL_QUADS);//kaki depan 2 kanan
    glColor3f(0.2,0.8,0.7);
	glVertex3f(10,-15,15);
	glVertex3f(15,-15,10);
	glVertex3f(25,-15,10);
	glVertex3f(30,-15,15);
	glEnd();
	glBegin(GL_QUADS);//kaki depan 2 kanan
    glColor3f(0.6,0.8,0.3);
	glVertex3f(30,-15,15);
	glVertex3f(30,-15,0);
	glVertex3f(25,-15,0);
	glVertex3f(25,-15,10);
	glEnd();
	//
	glBegin(GL_QUADS);//kaki kanan tengah pertama
    glColor3f(0.6,0.8,0.3);
	glVertex3f(10,-5,0);
	glVertex3f(10,-5,15);
	glVertex3f(15,-5,10);
	glVertex3f(15,-5,0);
	glEnd();
	glBegin(GL_QUADS);//kaki kanan tengah pertama
    glColor3f(0.2,0.8,0.7);
	glVertex3f(10,-5,15);
	glVertex3f(15,-5,10);
	glVertex3f(25,-5,10);
	glVertex3f(30,-5,15);
	glEnd();
	glBegin(GL_QUADS);//kaki kanan tengah pertama
    glColor3f(0.6,0.8,0.3);
	glVertex3f(30,-5,15);
	glVertex3f(30,-5,0);
	glVertex3f(25,-5,0);
	glVertex3f(25,-5,10);
	glEnd();
	glBegin(GL_QUADS);//kaki kanan tengah
    glColor3f(0.6,0.8,0.3);
	glVertex3f(10,0,0);
	glVertex3f(10,0,15);
	glVertex3f(15,0,10);
	glVertex3f(15,0,0);
	glEnd();
	glBegin(GL_QUADS);//kaki kanan tengah
    glColor3f(0.2,0.8,0.7);
	glVertex3f(10,0,15);
	glVertex3f(15,0,10);
	glVertex3f(25,0,10);
	glVertex3f(30,0,15);
	glEnd();
	glBegin(GL_QUADS);//kaki kanan tengah
    glColor3f(0.6,0.8,0.3);
	glVertex3f(30,0,15);
	glVertex3f(30,0,0);
	glVertex3f(25,0,0);
	glVertex3f(25,0,10);
	glEnd();
	//
	glBegin(GL_QUADS);//kaki kanan belakang 1
    glColor3f(0.6,0.8,0.3);
	glVertex3f(10,20,0);
	glVertex3f(10,20,15);
	glVertex3f(15,20,10);
	glVertex3f(15,20,0);
	glEnd();
	glBegin(GL_QUADS);//kaki kanan belakang 1
    glColor3f(0.2,0.8,0.7);
	glVertex3f(10,20,15);
	glVertex3f(15,20,10);
	glVertex3f(25,20,10);
	glVertex3f(30,20,15);
	glEnd();
	glBegin(GL_QUADS);//kaki kanan belakang 1
    glColor3f(0.6,0.8,0.3);
	glVertex3f(30,20,15);
	glVertex3f(30,20,0);
	glVertex3f(25,20,0);
	glVertex3f(25,20,10);
	glEnd();
	glBegin(GL_QUADS);//kaki kanan belakang 2
    glColor3f(0.6,0.8,0.3);
	glVertex3f(10,15,0);
	glVertex3f(10,15,15);
	glVertex3f(15,15,10);
	glVertex3f(15,15,0);
	glEnd();
	glBegin(GL_QUADS);//kaki kanan belakang 2
    glColor3f(0.2,0.8,0.7);
	glVertex3f(10,15,15);
	glVertex3f(15,15,10);
	glVertex3f(25,15,10);
	glVertex3f(30,15,15);
	glEnd();
	glBegin(GL_QUADS);//kaki kanan belakang 2
    glColor3f(0.6,0.8,0.3);
	glVertex3f(30,15,15);
	glVertex3f(30,15,0);
	glVertex3f(25,15,0);
	glVertex3f(25,15,10);
	glEnd();
	//
	glBegin(GL_QUADS);//kaki kanan belakang tengah 1
    glColor3f(0.6,0.8,0.3);
	glVertex3f(10,5,0);
	glVertex3f(10,5,15);
	glVertex3f(15,5,10);
	glVertex3f(15,5,0);
	glEnd();
	glBegin(GL_QUADS);//kaki kanan belakang tengah 1
    glColor3f(0.2,0.8,0.7);
	glVertex3f(10,5,15);
	glVertex3f(15,5,10);
	glVertex3f(25,5,10);
	glVertex3f(30,5,15);
	glEnd();
	glBegin(GL_QUADS);//kaki kanan belakang tengah 1
    glColor3f(0.6,0.8,0.3);
	glVertex3f(30,5,15);
	glVertex3f(30,5,0);
	glVertex3f(25,5,0);
	glVertex3f(25,5,10);
	glEnd();
	//sisi
	glBegin(GL_QUADS);//kaki sisi kanan 1
    glColor3f(0.6,0.8,0.3);
	glVertex3f(30,-20,0);
	glVertex3f(30,-20,15);
	glVertex3f(30,-15,10);
	glVertex3f(30,-15,0);
	glEnd();
	glBegin(GL_QUADS);//kaki sisi kanan 1
    glColor3f(0.6,0.8,0.3);
	glVertex3f(30,20,0);
	glVertex3f(30,20,15);
	glVertex3f(30,15,10);
	glVertex3f(30,15,0);
	glEnd();
	glBegin(GL_QUADS);//kaki sisi kanan 1
    glColor3f(0.2,0.8,0.7);
	glVertex3f(30,-5,10);
	glVertex3f(30,-5,0);
	glVertex3f(30,5,0);
	glVertex3f(30,5,10);
	glEnd();
	glBegin(GL_QUADS);//kaki sisi kanan 1
    glColor3f(0.6,0.8,0.7);
	glVertex3f(30,-20,15);
	glVertex3f(30,-15,10);
	glVertex3f(30,15,10);
	glVertex3f(30,20,15);
	glEnd();
	//
	glBegin(GL_QUADS);//kaki sisi kanan 2
    glColor3f(0.6,0.8,0.3);
	glVertex3f(25,-20,0);
	glVertex3f(25,-20,15);
	glVertex3f(25,-15,10);
	glVertex3f(25,-15,0);
	glEnd();
	glBegin(GL_QUADS);//kaki sisi kanan 2
    glColor3f(0.6,0.8,0.3);
	glVertex3f(25,20,0);
	glVertex3f(25,20,15);
	glVertex3f(25,15,10);
	glVertex3f(25,15,0);
	glEnd();
	glBegin(GL_QUADS);//kaki sisi kanan 2
    glColor3f(0.2,0.8,0.7);
	glVertex3f(25,-5,10);
	glVertex3f(25,-5,0);
	glVertex3f(25,5,0);
	glVertex3f(25,5,10);
	glEnd();
	glBegin(GL_QUADS);//kaki sisi kanan 2
    glColor3f(0.6,0.8,0.7);
	glVertex3f(25,-20,15);
	glVertex3f(25,-15,10);
	glVertex3f(25,15,10);
	glVertex3f(25,20,15);
	glEnd();
	glBegin(GL_QUADS);//kaki sisi kanan 3
    glColor3f(0.6,0.8,0.3);
	glVertex3f(15,-20,0);
	glVertex3f(15,-20,15);
	glVertex3f(15,-15,10);
	glVertex3f(15,-15,0);
	glEnd();
	glBegin(GL_QUADS);//kaki sisi kanan 3
    glColor3f(0.6,0.8,0.3);
	glVertex3f(15,20,0);
	glVertex3f(15,20,15);
	glVertex3f(15,15,10);
	glVertex3f(15,15,0);
	glEnd();
	glBegin(GL_QUADS);//kaki sisi kanan 3
    glColor3f(0.2,0.8,0.7);
	glVertex3f(15,-5,10);
	glVertex3f(15,-5,0);
	glVertex3f(15,5,0);
	glVertex3f(15,5,10);
	glEnd();
	glBegin(GL_QUADS);//kaki sisi kanan 3
    glColor3f(0.6,0.8,0.7);
	glVertex3f(15,-20,15);
	glVertex3f(15,-15,10);
	glVertex3f(15,15,10);
	glVertex3f(15,20,15);
	glEnd();
	//
	glBegin(GL_QUADS);//kaki sisi kanan 4
    glColor3f(0.6,0.8,0.3);
	glVertex3f(10,-20,0);
	glVertex3f(10,-20,15);
	glVertex3f(10,-15,10);
	glVertex3f(10,-15,0);
	glEnd();
	glBegin(GL_QUADS);//kaki sisi kanan 4
    glColor3f(0.6,0.8,0.3);
	glVertex3f(10,20,0);
	glVertex3f(10,20,15);
	glVertex3f(10,15,10);
	glVertex3f(10,15,0);
	glEnd();
	glBegin(GL_QUADS);//kaki sisi kanan 4
    glColor3f(0.2,0.8,0.7);
	glVertex3f(10,-5,10);
	glVertex3f(10,-5,0);
	glVertex3f(10,5,0);
	glVertex3f(10,5,10);
	glEnd();
	glBegin(GL_QUADS);//kaki sisi kanan 4
    glColor3f(0.6,0.8,0.7);
	glVertex3f(10,-20,15);
	glVertex3f(10,-15,10);
	glVertex3f(10,15,10);
	glVertex3f(10,20,15);
	glEnd();

	//kaki kiri
    glBegin(GL_QUADS);//kaki depan kanan
    glColor3f(0.6,0.8,0.3);
	glVertex3f(-10,-20,0);
	glVertex3f(-10,-20,15);
	glVertex3f(-15,-20,10);
	glVertex3f(-15,-20,0);
	glEnd();
	glBegin(GL_QUADS);//kaki depan kanan
    glColor3f(0.2,0.8,0.7);
	glVertex3f(-10,-20,15);
	glVertex3f(-15,-20,10);
	glVertex3f(-25,-20,10);
	glVertex3f(-30,-20,15);
	glEnd();
	glBegin(GL_QUADS);//kaki depan kanan
    glColor3f(0.6,0.8,0.3);
	glVertex3f(-30,-20,15);
	glVertex3f(-30,-20,0);
	glVertex3f(-25,-20,0);
	glVertex3f(-25,-20,10);
	glEnd();
	//
	glBegin(GL_QUADS);//kaki depan 2 kanan
    glColor3f(0.6,0.8,0.3);
	glVertex3f(-10,-15,0);
	glVertex3f(-10,-15,15);
	glVertex3f(-15,-15,10);
	glVertex3f(-15,-15,0);
	glEnd();
	glBegin(GL_QUADS);//kaki depan 2 kanan
    glColor3f(0.2,0.8,0.7);
	glVertex3f(-10,-15,15);
	glVertex3f(-15,-15,10);
	glVertex3f(-25,-15,10);
	glVertex3f(-30,-15,15);
	glEnd();
	glBegin(GL_QUADS);//kaki depan 2 kanan
    glColor3f(0.6,0.8,0.3);
	glVertex3f(-30,-15,15);
	glVertex3f(-30,-15,0);
	glVertex3f(-25,-15,0);
	glVertex3f(-25,-15,10);
	glEnd();
	//
	glBegin(GL_QUADS);//kaki kanan tengah pertama
    glColor3f(0.6,0.8,0.3);
	glVertex3f(-10,-5,0);
	glVertex3f(-10,-5,15);
	glVertex3f(-15,-5,10);
	glVertex3f(-15,-5,0);
	glEnd();
	glBegin(GL_QUADS);//kaki kanan tengah pertama
    glColor3f(0.2,0.8,0.7);
	glVertex3f(-10,-5,15);
	glVertex3f(-15,-5,10);
	glVertex3f(-25,-5,10);
	glVertex3f(-30,-5,15);
	glEnd();
	glBegin(GL_QUADS);//kaki kanan tengah pertama
    glColor3f(0.6,0.8,0.3);
	glVertex3f(-30,-5,15);
	glVertex3f(-30,-5,0);
	glVertex3f(-25,-5,0);
	glVertex3f(-25,-5,10);
	glEnd();
	glBegin(GL_QUADS);//kaki kanan tengah
    glColor3f(0.6,0.8,0.3);
	glVertex3f(-10,0,0);
	glVertex3f(-10,0,15);
	glVertex3f(-15,0,10);
	glVertex3f(-15,0,0);
	glEnd();
	glBegin(GL_QUADS);//kaki kanan tengah
    glColor3f(0.2,0.8,0.7);
	glVertex3f(-10,0,15);
	glVertex3f(-15,0,10);
	glVertex3f(-25,0,10);
	glVertex3f(-30,0,15);
	glEnd();
	glBegin(GL_QUADS);//kaki kanan tengah
    glColor3f(0.6,0.8,0.3);
	glVertex3f(-30,0,15);
	glVertex3f(-30,0,0);
	glVertex3f(-25,0,0);
	glVertex3f(-25,0,10);
	glEnd();
	//
	glBegin(GL_QUADS);//kaki kanan belakang 1
    glColor3f(0.6,0.8,0.3);
	glVertex3f(-10,20,0);
	glVertex3f(-10,20,15);
	glVertex3f(-15,20,10);
	glVertex3f(-15,20,0);
	glEnd();
	glBegin(GL_QUADS);//kaki kanan belakang 1
    glColor3f(0.2,0.8,0.7);
	glVertex3f(-10,20,15);
	glVertex3f(-15,20,10);
	glVertex3f(-25,20,10);
	glVertex3f(-30,20,15);
	glEnd();
	glBegin(GL_QUADS);//kaki kanan belakang 1
    glColor3f(0.6,0.8,0.3);
	glVertex3f(-30,20,15);
	glVertex3f(-30,20,0);
	glVertex3f(-25,20,0);
	glVertex3f(-25,20,10);
	glEnd();
	glBegin(GL_QUADS);//kaki kanan belakang 2
    glColor3f(0.6,0.8,0.3);
	glVertex3f(-10,15,0);
	glVertex3f(-10,15,15);
	glVertex3f(-15,15,10);
	glVertex3f(-15,15,0);
	glEnd();
	glBegin(GL_QUADS);//kaki kanan belakang 2
    glColor3f(0.2,0.8,0.7);
	glVertex3f(-10,15,15);
	glVertex3f(-15,15,10);
	glVertex3f(-25,15,10);
	glVertex3f(-30,15,15);
	glEnd();
	glBegin(GL_QUADS);//kaki kanan belakang 2
    glColor3f(0.6,0.8,0.3);
	glVertex3f(-30,15,15);
	glVertex3f(-30,15,0);
	glVertex3f(-25,15,0);
	glVertex3f(-25,15,10);
	glEnd();
	//
	glBegin(GL_QUADS);//kaki kanan belakang tengah 1
    glColor3f(0.6,0.8,0.3);
	glVertex3f(-10,5,0);
	glVertex3f(-10,5,15);
	glVertex3f(-15,5,10);
	glVertex3f(-15,5,0);
	glEnd();
	glBegin(GL_QUADS);//kaki kanan belakang tengah 1
    glColor3f(0.2,0.8,0.7);
	glVertex3f(-10,5,15);
	glVertex3f(-15,5,10);
	glVertex3f(-25,5,10);
	glVertex3f(-30,5,15);
	glEnd();
	glBegin(GL_QUADS);//kaki kanan belakang tengah 1
    glColor3f(0.6,0.8,0.3);
	glVertex3f(-30,5,15);
	glVertex3f(-30,5,0);
	glVertex3f(-25,5,0);
	glVertex3f(-25,5,10);
	glEnd();
	//sisi
	glBegin(GL_QUADS);//kaki sisi kanan 1
    glColor3f(0.6,0.8,0.3);
	glVertex3f(-30,-20,0);
	glVertex3f(-30,-20,15);
	glVertex3f(-30,-15,10);
	glVertex3f(-30,-15,0);
	glEnd();
	glBegin(GL_QUADS);//kaki sisi kanan 1
    glColor3f(0.6,0.8,0.3);
	glVertex3f(-30,20,0);
	glVertex3f(-30,20,15);
	glVertex3f(-30,15,10);
	glVertex3f(-30,15,0);
	glEnd();
	glBegin(GL_QUADS);//kaki sisi kanan 1
    glColor3f(0.2,0.8,0.7);
	glVertex3f(-30,-5,10);
	glVertex3f(-30,-5,0);
	glVertex3f(-30,5,0);
	glVertex3f(-30,5,10);
	glEnd();
	glBegin(GL_QUADS);//kaki sisi kanan 1
    glColor3f(0.6,0.8,0.7);
	glVertex3f(-30,-20,15);
	glVertex3f(-30,-15,10);
	glVertex3f(-30,15,10);
	glVertex3f(-30,20,15);
	glEnd();
	//
	glBegin(GL_QUADS);//kaki sisi kanan 2
    glColor3f(0.6,0.8,0.3);
	glVertex3f(-25,-20,0);
	glVertex3f(-25,-20,15);
	glVertex3f(-25,-15,10);
	glVertex3f(-25,-15,0);
	glEnd();
	glBegin(GL_QUADS);//kaki sisi kanan 2
    glColor3f(0.6,0.8,0.3);
	glVertex3f(-25,20,0);
	glVertex3f(-25,20,15);
	glVertex3f(-25,15,10);
	glVertex3f(-25,15,0);
	glEnd();
	glBegin(GL_QUADS);//kaki sisi kanan 2
    glColor3f(0.2,0.8,0.7);
	glVertex3f(-25,-5,10);
	glVertex3f(-25,-5,0);
	glVertex3f(-25,5,0);
	glVertex3f(-25,5,10);
	glEnd();
	glBegin(GL_QUADS);//kaki sisi kanan 2
    glColor3f(0.6,0.8,0.7);
	glVertex3f(-25,-20,15);
	glVertex3f(-25,-15,10);
	glVertex3f(-25,15,10);
	glVertex3f(-25,20,15);
	glEnd();
	glBegin(GL_QUADS);//kaki sisi kanan 3
    glColor3f(0.6,0.8,0.3);
	glVertex3f(-15,-20,0);
	glVertex3f(-15,-20,15);
	glVertex3f(-15,-15,10);
	glVertex3f(-15,-15,0);
	glEnd();
	glBegin(GL_QUADS);//kaki sisi kanan 3
    glColor3f(0.6,0.8,0.3);
	glVertex3f(-15,20,0);
	glVertex3f(-15,20,15);
	glVertex3f(-15,15,10);
	glVertex3f(-15,15,0);
	glEnd();
	glBegin(GL_QUADS);//kaki sisi kanan 3
    glColor3f(0.2,0.8,0.7);
	glVertex3f(-15,-5,10);
	glVertex3f(-15,-5,0);
	glVertex3f(-15,5,0);
	glVertex3f(-15,5,10);
	glEnd();
	glBegin(GL_QUADS);//kaki sisi kanan 3
    glColor3f(0.6,0.8,0.7);
	glVertex3f(-15,-20,15);
	glVertex3f(-15,-15,10);
	glVertex3f(-15,15,10);
	glVertex3f(-15,20,15);
	glEnd();
	//
	glBegin(GL_QUADS);//kaki sisi kanan 4
    glColor3f(0.6,0.8,0.3);
	glVertex3f(-10,-20,0);
	glVertex3f(-10,-20,15);
	glVertex3f(-10,-15,10);
	glVertex3f(-10,-15,0);
	glEnd();
	glBegin(GL_QUADS);//kaki sisi kanan 4
    glColor3f(0.6,0.8,0.3);
	glVertex3f(-10,20,0);
	glVertex3f(-10,20,15);
	glVertex3f(-10,15,10);
	glVertex3f(-10,15,0);
	glEnd();
	glBegin(GL_QUADS);//kaki sisi kanan 4
    glColor3f(0.2,0.8,0.7);
	glVertex3f(-10,-5,10);
	glVertex3f(-10,-5,0);
	glVertex3f(-10,5,0);
	glVertex3f(-10,5,10);
	glEnd();
	glBegin(GL_QUADS);//kaki sisi kanan 4
    glColor3f(0.6,0.8,0.7);
	glVertex3f(-10,-20,15);
	glVertex3f(-10,-15,10);
	glVertex3f(-10,15,10);
	glVertex3f(-10,20,15);
	glEnd();

	//lanta
	for(i=0 ;i<=8; i++){
	    glColor3f(0.8-(i*0.2),0.8+(i*0.1),1-(i*0.1));
        for(j=0 ;j<=i; j++){
        glBegin(GL_QUADS);
//        glColor3f(0.8,0.8,1);
        glVertex3f(10,-20,15+(j*10));
        glVertex3f(30,-20,15+(j*10));
        glVertex3f(30,20,15+(j*10));
        glVertex3f(10,20,15+(j*10));
        glEnd();
        glBegin(GL_QUADS);
    //    glColor3f(0.8,0.8,1);
        glVertex3f(-10,-20,15+(j*10));
        glVertex3f(-30,-20,15+(j*10));
        glVertex3f(-30,20,15+(j*10));
        glVertex3f(-10,20,15+(j*10));
        glEnd();
        }

	}





}
void atap(void){



    //Tembok depan
    glBegin(GL_POLYGON);// Depan kiri
    glColor3f(0,0.1,0.2);
	glVertex3f(-30,-20,15);
	glVertex3f(-10,-20,15);
	glColor3f(1,1,0.7);
	glVertex3f(-10,-20,100);
	glVertex3f(-30,-20,100);
	glEnd();
	glBegin(GL_POLYGON);//Depan kanan
    glColor3f(0,0.1,0.2);
	glVertex3f(30,-20,15);
	glVertex3f(10,-20,15);
	glColor3f(1,1,0.7);
	glVertex3f(10,-20,100);
	glVertex3f(30,-20,100);
	glEnd();
    glBegin(GL_POLYGON);//jajar genjang depan
//    glColor3f(0.85,0.85,0.97);
    glColor3f(1,1,0.7);
	glVertex3f(-30,-20,100);
	glVertex3f(30,-20,100);
	glColor3f(1,1,0.7);
	glVertex3f(25,-20,110);
	glVertex3f(-25,-20,110);
	glEnd();
    glBegin(GL_POLYGON);// Depan quads atas
    glColor3f(1,1,0.7);
	glVertex3f(-25,-20,110);
	glVertex3f(25,-20,110);
	glColor3f(0.85,0.85,0.97);
	glVertex3f(25,-20,145);
	glVertex3f(-25,-20,145);
	glEnd();
	glBegin(GL_TRIANGLES);//triangle atas Depan
    glColor3f(0.85,0.85,0.97);
	glVertex3f(-25,-20,145);
	glVertex3f(25,-20,145);
	glColor3f(1,1,0.7);
	glVertex3f(0,-20,165);
	glEnd();

	//
	//jendela garis
	for(i=0; i<=4; i++){

            glBegin(GL_LINE_STRIP);//depan kanan
            glColor3f(1,1,1);
            glVertex3f(10+(i*5),-20,15);
            glVertex3f(10+(i*5),-20,100);
//            glVertex3f(20,-20.1,100);
//            glVertex3f(20,-20.1,15);
//            glVertex3f(25,-20.1,15);
//            glVertex3f(25,-20.1,100);
            glEnd();
                        glBegin(GL_LINE_STRIP);//depan kiri
            glColor3f(1,1,1);
            glVertex3f(-10-(i*5),-20,15);
            glVertex3f(-10-(i*5),-20,100);
            glEnd();
	}

	for(i=0; i<=20; i++){
            glBegin(GL_LINE_LOOP);//kanan lvl 1 naik
            glColor3f(1,1,1);
            glVertex3f(10,-20.1,15+(i*4.25));
            glVertex3f(30,-20.1,15+(i*4.25));
            glEnd();
            glBegin(GL_LINE_LOOP);//kiri lvl 1 nyamping
            glColor3f(1,1,1);
            glVertex3f(-30,-20.1,15+(i*4.25));
            glVertex3f(-10,-20.1,15+(i*4.25));
            glEnd();
	}
	for(i=0; i<=10; i++){
            glBegin(GL_LINE_STRIP);//front
            glColor3f(1,1,1);
            glVertex3f(-25+(i*5),-20,110);
            glVertex3f(-25+(i*5),-20,145);
            glEnd();
	}
	for(i=0; i<=7; i++){
            glBegin(GL_LINE_STRIP);//front
            glColor3f(1,1,1);
            glVertex3f(-25,-20,110+(i*5));
            glVertex3f(25,-20,110+(i*5));
            glEnd();
	}
	for(i=0; i<=7; i++){
            glBegin(GL_LINE_STRIP);//front
            glColor3f(1,1,1);
            glVertex3f(-25,-20,110+(i*5));
            glVertex3f(25,-20,110+(i*5));
            glEnd();
	}

}
void lawang(void){

//naik level 1
    for(i=0; i<=4; i++){
        for(j=i; j<=i; j++){
//            glBegin(GL_LINE_STRIP);//depan kanan
//            glColor3f(1,1,1);
//            glVertex3f(10+(i*5),-20,15);
//            glVertex3f(10+(i*5),-20,100);
////            glVertex3f(20,-20.1,100);
////            glVertex3f(20,-20.1,15);
////            glVertex3f(25,-20.1,15);
////            glVertex3f(25,-20.1,100);
//            glEnd();
            glBegin(GL_LINE_STRIP);//belakang kanan
            glColor3f(1,1,1);
            glVertex3f(10+(i*5),20,15);
            glVertex3f(10+(i*5),20,100);
            glEnd();
            glBegin(GL_LINE_STRIP);//belakang kiri
            glColor3f(1,1,1);
            glVertex3f(-10+(i*-5),20,15);
            glVertex3f(-10+(i*-5),20,100);
            glEnd();
//            glBegin(GL_LINE_STRIP);//depan kiri
//            glColor3f(1,1,1);
//            glVertex3f(-10+(i*-5),-20,15);
//            glVertex3f(-10+(i*-5),-20,100);
//            glEnd();
            //samping
            glBegin(GL_LINE_STRIP);//samping kanan
            glColor3f(1,1,1);
            glVertex3f(30,-20+(i*+5),15);
            glVertex3f(30,-20+(i*+5),100);
            glEnd();
            glBegin(GL_LINE_STRIP);//samping kanan
            glColor3f(1,1,1);
            glVertex3f(30,20+(i*-5),15);
            glVertex3f(30,20+(i*-5),100);
            glEnd();
            glBegin(GL_LINE_STRIP);//samping kiri
            glColor3f(1,1,1);
            glVertex3f(-30,-20+(i*+5),15);
            glVertex3f(-30,-20+(i*+5),100);
            glEnd();
            glBegin(GL_LINE_STRIP);//samping kiri
            glColor3f(1,1,1);
            glVertex3f(-30,20+(i*-5),15);
            glVertex3f(-30,20+(i*-5),100);
            glEnd();
            glBegin(GL_LINE_STRIP);//samping tengah kanan
            glColor3f(1,1,1);
            glVertex3f(10,-20+(i*+5),15);
            glVertex3f(10,-20+(i*+5),100);
            glEnd();
            glBegin(GL_LINE_STRIP);//samping tengah kanan
            glColor3f(1,1,1);
            glVertex3f(10,20+(i*-5),15);
            glVertex3f(10,20+(i*-5),100);
            glEnd();
            glBegin(GL_LINE_STRIP);//samping tengah kiri
            glColor3f(1,1,1);
            glVertex3f(-10,-20+(i*+5),15);
            glVertex3f(-10,-20+(i*+5),100);
            glEnd();
            glBegin(GL_LINE_STRIP);//samping tengah kiri
            glColor3f(1,1,1);
            glVertex3f(-10,20+(i*-5),15);
            glVertex3f(-10,20+(i*-5),100);
            glEnd();
        }
    }
    //ke samping level 1
    for(i=0; i<=20; i++){
//            glBegin(GL_LINE_LOOP);//kanan lvl 1 nyamping
//            glColor3f(1,1,1);
//            glVertex3f(10,-20.1,15+(i*4.25));
//            glVertex3f(30,-20.1,15+(i*4.25));
//            glEnd();
            glBegin(GL_LINE_LOOP);//kanan belakang lvl 1 nyamping
            glColor3f(1,1,1);
            glVertex3f(10,20.1,15+(i*4.25));
            glVertex3f(30,20.1,15+(i*4.25));
            glEnd();
                        glBegin(GL_LINE_LOOP);//kiri belakang lvl 1 nyamping
            glColor3f(1,1,1);
            glVertex3f(-10,20.1,15+(i*4.25));
            glVertex3f(-30,20.1,15+(i*4.25));
            glEnd();
//                        glBegin(GL_LINE_LOOP);//kiri depan lvl 1 nyamping
//            glColor3f(1,1,1);
//            glVertex3f(-10,-20.1,15+(i*4.25));
//            glVertex3f(-30,-20.1,15+(i*4.25));
//            glEnd();
                        glBegin(GL_LINE_LOOP);//sisi kanan luar
            glColor3f(1,1,1);
            glVertex3f(30.1,-20,15+(i*4.25));
            glVertex3f(30.1,20,15+(i*4.25));
            glEnd();
            glBegin(GL_LINE_LOOP);//sisi kiri luar
            glColor3f(1,1,1);
            glVertex3f(-30.1,-20,15+(i*4.25));
            glVertex3f(-30.1,20,15+(i*4.25));
            glEnd();
            glBegin(GL_LINE_LOOP);//sisi kanan dalam
            glColor3f(1,1,1);
            glVertex3f(9.98,-20,15+(i*4.25));
            glVertex3f(9.98,20,15+(i*4.25));
            glEnd();
            glBegin(GL_LINE_LOOP);//sisi kiri dalam
            glColor3f(1,1,1);
            glVertex3f(-9.98,-20,15+(i*4.25));
            glVertex3f(-9.98,20,15+(i*4.25));
            glEnd();
    }
    //naik depan belakang lvl 3
    for(i=0; i<=10; i++){
        for(j=i; j<=i; j++){
//            glBegin(GL_LINE_STRIP);//front
//            glColor3f(1,1,1);
//            glVertex3f(-25+(i*5),-20,110);
//            glVertex3f(-25+(i*5),-20,145);
//            glEnd();
            glBegin(GL_LINE_STRIP);//back
            glColor3f(1,1,1);
            glVertex3f(-25+(i*5),20,110);
            glVertex3f(-25+(i*5),20,145);
            glEnd();
        }
    }
    //nyamping lvl 3
    for(i=0; i<=7; i++){
        for(j=i; j<=i; j++){
//            glBegin(GL_LINE_STRIP);//front
//            glColor3f(1,1,1);
//            glVertex3f(-25,-20,110+(i*5));
//            glVertex3f(25,-20,110+(i*5));
//            glEnd();
            glBegin(GL_LINE_STRIP);//back
            glColor3f(1,1,1);
            glVertex3f(-25,20,110+(i*5));
            glVertex3f(25,20,110+(i*5));
            glEnd();
            glBegin(GL_LINE_STRIP);//left
            glColor3f(1,1,1);
            glVertex3f(-25,-20,110+(i*5));
            glVertex3f(-25,20,110+(i*5));
            glEnd();
            glBegin(GL_LINE_STRIP);//right
            glColor3f(1,1,1);
            glVertex3f(25,-20,110+(i*5));
            glVertex3f(25,20,110+(i*5));
            glEnd();
        }
    }
    //sgi3 front end naik
    for(i=0; i<=5; i++){
        for(j=i; j<=i; j++){
            glBegin(GL_LINE_STRIP);//
            glColor3f(1,1,1);
            glVertex3f(-25+(i*5),-20,145);
            glVertex3f(-25+(i*5),-20,145+(i*4));
            glEnd();
            glBegin(GL_LINE_STRIP);//
            glColor3f(1,1,1);
            glVertex3f(0+(i*5),-20,165+(i*-4));
            glVertex3f(0+(i*5),-20,145);
            glEnd();
            //
            glBegin(GL_LINE_STRIP);//
            glColor3f(1,1,1);
            glVertex3f(-25+(i*5),20,145);
            glVertex3f(-25+(i*5),20,145+(i*4));
            glEnd();
            glBegin(GL_LINE_STRIP);//
            glColor3f(1,1,1);
            glVertex3f(0+(i*5),20,165+(i*-4));
            glVertex3f(0+(i*5),20,145);
            glEnd();

        }
    }
//    //nyamping 3
//    for(i=0; i<=5; i++){
//        for(j=i; j<=i; j++){
//            glBegin(GL_LINE_STRIP);//
//            glColor3f(1,1,1);
//            glVertex3f(-25+(i*5),-20,145);
//            glVertex3f(-25+(i*5),-20,145+(i*4));
//            glEnd();
//            glBegin(GL_LINE_STRIP);//
//            glColor3f(1,1,1);
//            glVertex3f(0+(i*5),-20,165+(i*-4));
//            glVertex3f(0+(i*5),-20,145);
//            glEnd();
//            //
//            glBegin(GL_LINE_STRIP);//
//            glColor3f(1,1,1);
//            glVertex3f(-25+(i*5),20,145);
//            glVertex3f(-25+(i*5),20,145+(i*4));
//            glEnd();
//            glBegin(GL_LINE_STRIP);//
//            glColor3f(1,1,1);
//            glVertex3f(0+(i*5),20,165+(i*-4));
//            glVertex3f(0+(i*5),20,145);
//            glEnd();
//
//        }
//    }
    //lv1 3 naik side
    for(i=0; i<=8; i++){
        for(j=i; j<=i; j++){
            glBegin(GL_LINE_STRIP);//side
            glColor3f(1,1,1);
            glVertex3f(-25,-20+(i*5),110);
            glVertex3f(-25,-20+(i*5),145);
            glEnd();
            glBegin(GL_LINE_STRIP);//side
            glColor3f(1,1,1);
            glVertex3f(25,-20+(i*5),110);
            glVertex3f(25,-20+(i*5),145);
            glEnd();
        }
    }

    //jjr enjang front
    for(i=0; i<=10; i++){
        glBegin(GL_LINE_STRIP);//jajar genjang depan
    glColor3f(0.85,0.85,0.97);
	glVertex3f(-25+(i*5),-20,100);
//	glVertex3f(30,-20,100);
//	glColor3f(1,1,0.7);
//	glVertex3f(25,-20,110);
	glVertex3f(-25+(i*5),-20,110);
	glEnd();
    }
    for(i=0; i<=2; i++){
        glBegin(GL_LINE_STRIP);//jajar genjang depan
    glColor3f(0.85,0.85,0.97);
	glVertex3f(-30+(i*2.5),-20,100+(i*5));
//	glVertex3f(30,-20,100);
//	glColor3f(1,1,0.7);
//	glVertex3f(25,-20,110);
	glVertex3f(30-(i*2.5),-20,100+(i*5));
	glEnd();
    }
            //back
    for(i=0; i<=10; i++){
        glBegin(GL_LINE_STRIP);//jajar genjang depan
    glColor3f(0.85,0.85,0.97);
	glVertex3f(-25+(i*5),20,100);
	glVertex3f(-25+(i*5),20,110);
	glEnd();
    }
    for(i=0; i<=2; i++){
        glBegin(GL_LINE_STRIP);//jajar genjang depan
    glColor3f(0.85,0.85,0.97);
	glVertex3f(-30+(i*2.5),20,100+(i*5));
	glVertex3f(30-(i*2.5),20,100+(i*5));
	glEnd();
    }



}


void display(void)
{
    if (is_depth)
        tampil();
    else
        hilang();
}

void idle()
{
	if (!mouseDown)
	{
		xrot += 0.3f;
		yrot += 0.4f;
	}
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{


{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mouseDown = true;
		xdiff = x - yrot;
		ydiff = -y + xrot;
	}
	else
	mouseDown = false;
}
tampil();
}


void keyboard(unsigned char key, int x, int y)
{

    switch(key)
    {
        case 'w':
        case 'W':
            glTranslated(0,0,3);
            break;
        case 'd':
        case 'D':
            glTranslated(3,0,0);
            break;
        case 's':
        case 'S':
            glTranslated(0,0,-3);
            break;
        case 'a':
        case 'A':
            glTranslated(-3,0,0);
            break;
        case '7':
            glTranslated(0,3,0);
            break;
        case '9':
            glTranslated(0,-3,0);
            break;
        case '2':
            glRotated(2,1,0,0);
            break;
        case '8':
            glRotated(-2,0,1,0);
            break;
        case '6':
            glRotated(2,0,1,0);
            break;
        case '4':
            glRotated(-2,1,0,0);
            break;
        case '1':
            glRotated(2,0,0,1);
            break;
        case '3':
            glRotated(-2,0,0,1);
            break;
        case '5':
            if (is_depth)
            {
                is_depth = 0;
                tampil();
            }
            else
            {
                is_depth = 1;
                hilang();
            }
    }
    display();


}
void posenggggg()
{
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(xrot, 1.0f,0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);
}

void mouseMotion(int x, int y)
{
    posenggggg();
    if (mouseDown)
    {
        yrot = x - xdiff;
        xrot = y + ydiff;
        glutPostRedisplay();

    }
}

void ukuran(int lebar, int tinggi)
{
    if(tinggi == 0) tinggi = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(-3.5, -15.0, -100.0);
    glMatrixMode(GL_MODELVIEW);
}

