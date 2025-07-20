#include <GL/glut.h>
#include <math.h>
#include <windows.h> // untuk Sleep

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

float angle = 0;

// --- KUBUS ---
void drawCube() {
    float v[8][3] = {
        {-1,-1,-1}, {1,-1,-1}, {1,1,-1}, {-1,1,-1},
        {-1,-1,1},  {1,-1,1},  {1,1,1},  {-1,1,1}
    };
    int face[6][4] = {
        {0,1,2,3},{4,5,6,7},{0,1,5,4},
        {2,3,7,6},{1,2,6,5},{0,3,7,4}
    };
    float color[6][3] = {
        {1,1,0}, {0,1,1}, {0,1,0},
        {0,0,1}, {1,0,1}, {1,0,0}
    };
    glPushMatrix();
    glTranslatef(-2.8,0,0);
    for(int i=0;i<6;i++) {
        glColor3fv(color[i]);
        glBegin(GL_QUADS);
        for(int j=0;j<4;j++)
            glVertex3fv(v[face[i][j]]);
        glEnd();
    }
    glPopMatrix();
}

// --- PRISMA SEGITIGA ---
void drawPrism() {
    float h = 1.4;
    float r = 1.0;
    float vertex[6][3];
    for(int i=0;i<3;i++) {
        float theta = 2*M_PI*i/3;
        vertex[i][0] = r*cos(theta);
        vertex[i][1] = r*sin(theta);
        vertex[i][2] = h/2;
        vertex[i+3][0] = r*cos(theta);
        vertex[i+3][1] = r*sin(theta);
        vertex[i+3][2] = -h/2;
    }
    glPushMatrix();
    glTranslatef(0,0,0);
    // Alas atas
    glColor3f(0,0,1);
    glBegin(GL_TRIANGLES);
    for(int i=0;i<3;i++) glVertex3fv(vertex[i]);
    glEnd();
    // Alas bawah
    glColor3f(1,1,0);
    glBegin(GL_TRIANGLES);
    for(int i=3;i<6;i++) glVertex3fv(vertex[i]);
    glEnd();
    // Sisi samping
    for(int i=0;i<3;i++) {
        glColor3f(0,1,1);
        glBegin(GL_QUADS);
        glVertex3fv(vertex[i]);
        glVertex3fv(vertex[(i+1)%3]);
        glVertex3fv(vertex[((i+1)%3)+3]);
        glVertex3fv(vertex[i+3]);
        glEnd();
    }
    glPopMatrix();
}

// --- BOLA (SPHERE) ---
void drawSphere(int n_lat, int n_long) {
    float R = 1.0;
    glPushMatrix();
    glTranslatef(2.8,0,0);
    for (int i = 0; i < n_lat; i++) {
        float lat0 = M_PI * (-0.5 + (float)i / n_lat);
        float lat1 = M_PI * (-0.5 + (float)(i+1) / n_lat);
        for (int j = 0; j < n_long; j++) {
            float lon0 = 2 * M_PI * (float)j / n_long;
            float lon1 = 2 * M_PI * (float)(j+1) / n_long;

            float x00 = R * cos(lat0) * cos(lon0);
            float y00 = R * sin(lat0);
            float z00 = R * cos(lat0) * sin(lon0);

            float x01 = R * cos(lat0) * cos(lon1);
            float y01 = R * sin(lat0);
            float z01 = R * cos(lat0) * sin(lon1);

            float x10 = R * cos(lat1) * cos(lon0);
            float y10 = R * sin(lat1);
            float z10 = R * cos(lat1) * sin(lon0);

            float x11 = R * cos(lat1) * cos(lon1);
            float y11 = R * sin(lat1);
            float z11 = R * cos(lat1) * sin(lon1);

            glBegin(GL_QUADS);
            glColor3f(fabs(x00),fabs(y00),fabs(z00));
            glVertex3f(x00,y00,z00);
            glColor3f(fabs(x01),fabs(y01),fabs(z01));
            glVertex3f(x01,y01,z01);
            glColor3f(fabs(x11),fabs(y11),fabs(z11));
            glVertex3f(x11,y11,z11);
            glColor3f(fabs(x10),fabs(y10),fabs(z10));
            glVertex3f(x10,y10,z10);
            glEnd();
        }
    }
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0,0,10, 0,0,0, 0,1,0);

    glRotatef(angle, 1,1,0.7);

    drawCube();
    drawPrism();
    drawSphere(20, 28);

    glutSwapBuffers();
}

void idle() {
    angle += 0.25;
    if(angle > 360) angle -= 360;
    Sleep(1); // Atur kecepatan animasi (ms)
    glutPostRedisplay();
}

void reshape(int w, int h) {
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION); glLoadIdentity();
    gluPerspective(60, (float)w/h, 1, 22);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(1100, 650);
    glutCreateWindow("3D Geometri: Kubus, Prisma Segitiga, Bola");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}
