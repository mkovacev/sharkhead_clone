#include <GL/glut.h>
#include  "funkcije.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "SOIL.h"

static void draw_debug_system(float x, float y, float z)
{
  glDisable(GL_LIGHTING);
  glPushMatrix();
    /*vektor po x osi */
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
      glVertex3f(x, y, z);
      glVertex3f(x+1.5, y, z);
    glEnd();
    /*vektor po y osi */
    glColor3f(0, 1, 0);
    glBegin(GL_LINES);
      glVertex3f(x, y, z);
      glVertex3f(x, y+1.5, z);
    glEnd();
    /*vektor po z osi */
    glColor3f(0, 0, 1);
    glBegin(GL_LINES);
      glVertex3f(x, y, z);
      glVertex3f(x, y, z+1.5);
    glEnd();
  glPopMatrix();
  glEnable(GL_LIGHTING);
  
}

static void draw_background()
{
  glPushMatrix();
    glDisable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);

      
      glEnable(GL_BACK);
      /* preuzeto sa https://www.khronos.org/opengl/wiki/Texturing_a_Sphere*/
      glBindTexture(GL_TEXTURE_2D, background_texture);
      glRotatef(-90, 1, 0, 0);
      glRotatef(180, 0, 0, 1);
      GLUquadricObj *sphere=NULL;
      sphere = gluNewQuadric();
      gluQuadricDrawStyle(sphere, GLU_FILL);
      gluQuadricTexture(sphere, true);
      gluQuadricNormals(sphere, GLU_SMOOTH);
      gluSphere(sphere, 30, 1000, 1000);
      glRotatef(90, 1, 0, 0);
      glDisable(GL_BACK);
    glDisable(GL_TEXTURE_2D);
  glPopMatrix();
}

static void draw_board()
{
  glPushMatrix();

  glColor3f(0, 1, 1);
    glBegin(GL_QUADS);
      /* bottom */
      glVertex3f(3, -0.5, 3);
      glVertex3f(3, -0.5, -3);
      glVertex3f(-3, -0.5, -3);
      glVertex3f(-3, -0.5, 3);

      /* sides */
      glNormal3f(0, 0, 1);
      glVertex3f(3, -0.5, 3);
      glVertex3f(3, 0.5, 3);
      glVertex3f(-3, 0.5, 3);
      glVertex3f(-3, -0.5, 3);

      glNormal3f(1, 0, 0);
      glVertex3f(3, 0.5, 3);
      glVertex3f(3, 0.5, -3);
      glVertex3f(3, -0.5, -3);
      glVertex3f(3, -0.5, 3);

      glNormal3f(-1, 0, 0);
      glVertex3f(3, 0.5, -3);
      glVertex3f(3, -0.5, -3);
      glVertex3f(-3, -0.5, -3);
      glVertex3f(-3, 0.5, -3);

      glNormal3f(0, 0, -1);
      glVertex3f(-3, 0.5, 3);
      glVertex3f(-3, 0.5, -3);
      glVertex3f(-3, -0.5, -3);
      glVertex3f(-3, -0.5, 3);
    glEnd();

    /* top */
    /* omogucavanje tekstura */
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, more);
    glBegin(GL_QUADS);
      glNormal3f(0, 1, 0);
      glTexCoord2f(1, 0);       
      glVertex3f(3, 0.5, 3);
      glTexCoord2f(1, 1);
      glVertex3f(3, 0.5, -3);
      glTexCoord2f(0, 1);
      glVertex3f(-3, 0.5, -3);
      glTexCoord2f(0, 0);
      glVertex3f(-3, 0.5, 3);
    glEnd();

    glScalef(6, 1, 6);
    glColor3f(1, 1, 1);
    //glutWireCube(1);
    glDisable(GL_TEXTURE_2D);
  glPopMatrix();
}

static void draw_button(float x, float z, float height)
{
  glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glColor3f(0, 0, 0);
    glTranslatef(x, height, z);
    //glutWireCube(1);
    glColor3f(0, 0.5, 1);
    
    glBegin(GL_QUADS);
    /* bottom */
      glVertex3f(0.5, -0.5, 0.5);
      glVertex3f(0.5, -0.5, -0.5);
      glVertex3f(-0.5, -0.5, -0.5);
      glVertex3f(-0.5, -0.5, 0.5);

      /* sides */
      glVertex3f(0.5, -0.5, 0.5);
      glVertex3f(0.5, 0.5, 0.5);
      glVertex3f(-0.5, 0.5, 0.5);
      glVertex3f(-0.5, -0.5, 0.5);

      glVertex3f(0.5, 0.5, 0.5);
      glVertex3f(0.5, 0.5, -0.5);
      glVertex3f(0.5, -0.5, -0.5);
      glVertex3f(0.5, -0.5, 0.5);

      glVertex3f(0.5, 0.5, -0.5);
      glVertex3f(0.5, -0.5, -0.5);
      glVertex3f(-0.5, -0.5, -0.5);
      glVertex3f(-0.5, 0.5, -0.5);

      glVertex3f(-0.5, 0.5, 0.5);
      glVertex3f(-0.5, 0.5, -0.5);
      glVertex3f(-0.5, -0.5, -0.5);
      glVertex3f(-0.5, -0.5, 0.5);
    glEnd();
  /* top */
    glColor3f(1, 1, 1);
    glBindTexture(GL_TEXTURE_2D, glava);
    glBegin(GL_QUADS);
      glNormal3f(0, 1, 0);
      glTexCoord2f(1, 0); 
      glVertex3f(0.5, 0.5, 0.5);
      glTexCoord2f(1, 1); 
      glVertex3f(0.5, 0.5, -0.5);
      glTexCoord2f(0, 1); 
      glVertex3f(-0.5, 0.5, -0.5);
      glTexCoord2f(0, 0); 
      glVertex3f(-0.5, 0.5, 0.5);
    glEnd();
    glDisable(GL_TEXTURE_2D);
  glPopMatrix();
}

static void pozicija_dugmica(int n, float h)
{
  height_array[n-1] = h;
  glutPostRedisplay();
}

static void reset()
{
    for (int i = 0; i<9; i++)
        height_array[i] = -0.01;
    glutPostRedisplay();
}

static void podizanje_dugmeta(int n)
{
    pozicija_dugmica(n, animation_parameter);
}

static void nacrtaj_cekic(float x, float y, float z)
{
  glPushMatrix();
    //translira se na zeljnu poziciju
    glTranslatef(x, y+0.2, z);
    
    //rotira se za 45 stepeni ceo cekic
    glRotatef(-45, 0, 1, 0);
    //na osnovu parametara translira se u odnosu na mesto gde treba da udari
    glTranslatef(rotacija_cekica_x, rotacija_cekica_y, 0);
    glRotatef(ugao_cekica, 0, 0, 1);
    
    glEnable(GL_TEXTURE_2D);
    glColor3f(1, 1, 1);
    //iscrtava se glava cekica
    glBindTexture(GL_TEXTURE_2D, metal);
    glBegin(GL_QUADS);
      /* gornje zarubljenje */
      glNormal3f(0, 1, 0);
      glTexCoord2f(0, 1); 
      glVertex3f(-0.45, 0.7, 0.45);
      glTexCoord2f(0, 0); 
      glVertex3f(0.45, 0.7, 0.45);
      glTexCoord2f(1, 0); 
      glVertex3f(0.45, 0.7, -0.45);
      glTexCoord2f(1, 1); 
      glVertex3f(-0.45, 0.7, -0.45);
      
      glTexCoord2f(0, 1); 
      glVertex3f(-0.45, 0.7, 0.45);
      glTexCoord2f(0, 0); 
      glVertex3f(0.45, 0.7, 0.45);
      glTexCoord2f(1, 0); 
      glVertex3f(0.55, 0.5, 0.55);
      glTexCoord2f(1, 1); 
      glVertex3f(-0.55, 0.5, 0.55);
      
      glTexCoord2f(0, 1); 
      glVertex3f(0.45, 0.7, 0.45);
      glTexCoord2f(0, 0); 
      glVertex3f(0.45, 0.7, -0.45);
      glTexCoord2f(1, 0); 
      glVertex3f(0.55, 0.5, -0.55);
      glTexCoord2f(1, 1); 
      glVertex3f(0.55, 0.5, 0.55);

      glTexCoord2f(0, 1); 
      glVertex3f(0.45, 0.7, -0.45);
      glTexCoord2f(0, 0); 
      glVertex3f(-0.45, 0.7, -0.45);
      glTexCoord2f(1, 0); 
      glVertex3f(-0.55, 0.5, -0.55);
      glTexCoord2f(1, 1); 
      glVertex3f(0.55, 0.5, -0.55);

      glTexCoord2f(0, 1); 
      glVertex3f(-0.45, 0.7, 0.45);
      glTexCoord2f(0, 0); 
      glVertex3f(-0.45, 0.7, -0.45);
      glTexCoord2f(1, 0); 
      glVertex3f(-0.55, 0.5, -0.55);
      glTexCoord2f(1, 1); 
      glVertex3f(-0.55, 0.5, 0.55);

      /* strane */
      glNormal3f(0, 0, 1);
      glTexCoord2f(0, 1);
      glNormal3f(0, 0, 1); 
      glVertex3f(-0.55, 0.5, 0.55);
      glTexCoord2f(0, 0); 
      glVertex3f(0.55, 0.5, 0.55);
      glTexCoord2f(1, 0); 
      glVertex3f(0.55, -0.5, 0.55);
      glTexCoord2f(1, 1); 
      glVertex3f(-0.55, -0.5, 0.55);

      glTexCoord2f(0, 1); 
      glVertex3f(0.55, 0.5, 0.55);
      glTexCoord2f(0, 0); 
      glVertex3f(0.55, 0.5, -0.55);
      glTexCoord2f(1, 0); 
      glVertex3f(0.55, -0.5, -0.55);
      glTexCoord2f(1, 1); 
      glVertex3f(0.55, -0.5, 0.55);

      glTexCoord2f(0, 1); 
      glVertex3f(0.55, 0.5, -0.55);
      glTexCoord2f(0, 0); 
      glVertex3f(-0.55, 0.5, -0.55);
      glTexCoord2f(1, 0); 
      glVertex3f(-0.55, -0.5, -0.55);
      glTexCoord2f(1, 1); 
      glVertex3f(0.55, -0.5, -0.55);

      glTexCoord2f(0, 1); 
      glVertex3f(-0.55, 0.5, -0.55);
      glTexCoord2f(0, 0); 
      glVertex3f(-0.55, 0.5, 0.55);
      glTexCoord2f(1, 0); 
      glVertex3f(-0.55, -0.5, 0.55);
      glTexCoord2f(1, 1); 
      glVertex3f(-0.55, -0.5, -0.55);

      /* donje zarubljenje */
      glTexCoord2f(0, 1); 
      glVertex3f(-0.45, -0.7, 0.45);
      glTexCoord2f(0, 0); 
      glVertex3f(0.45, -0.7, 0.45);
      glTexCoord2f(1, 0); 
      glVertex3f(0.45, -0.7, -0.45);
      glTexCoord2f(1, 1); 
      glVertex3f(-0.45, -0.7, -0.45);
      
      glTexCoord2f(0, 1); 
      glVertex3f(-0.45, -0.7, 0.45);
      glTexCoord2f(0, 0); 
      glVertex3f(0.45, -0.7, 0.45);
      glTexCoord2f(1, 0); 
      glVertex3f(0.55, -0.5, 0.55);
      glTexCoord2f(1, 1); 
      glVertex3f(-0.55, -0.5, 0.55);
      
      glTexCoord2f(0, 1); 
      glVertex3f(0.45, -0.7, 0.45);
      glTexCoord2f(0, 0); 
      glVertex3f(0.45, -0.7, -0.45);
      glTexCoord2f(1, 0); 
      glVertex3f(0.55, -0.5, -0.55);
      glTexCoord2f(1, 1); 
      glVertex3f(0.55, -0.5, 0.55);

      glTexCoord2f(0, 1); 
      glVertex3f(0.45, -0.7, -0.45);
      glTexCoord2f(0, 0); 
      glVertex3f(-0.45, -0.7, -0.45);
      glTexCoord2f(1, 0); 
      glVertex3f(-0.55, -0.5, -0.55);
      glTexCoord2f(1, 1); 
      glVertex3f(0.55, -0.5, -0.55);

      glTexCoord2f(0, 1); 
      glVertex3f(-0.45, -0.7, 0.45);
      glTexCoord2f(0, 0); 
      glVertex3f(-0.45, -0.7, -0.45);
      glTexCoord2f(1, 0); 
      glVertex3f(-0.55, -0.5, -0.55);
      glTexCoord2f(1, 1); 
      glVertex3f(-0.55, -0.5, 0.55);
    glEnd();
    
    /* boja za drsku cekica */
    glColor3f(0.5, 0.35, 0.05);
    /* drska cekica */
    glBindTexture(GL_TEXTURE_2D, drvo);
    glBegin(GL_QUADS);
      glTexCoord2f(0, 1); 
      glVertex3f(0, 0.1, -0.1);
      glTexCoord2f(0, 0); 
      glVertex3f(0, 0.1, 0.1);
      glTexCoord2f(1, 0); 
      glVertex3f(0, -0.1, 0.1);
      glTexCoord2f(1, 1); 
      glVertex3f(0, -0.1, -0.1);
      
      glTexCoord2f(0, 1);
      glVertex3f(0, 0.1, 0.1);
      glTexCoord2f(0, 0);
      glVertex3f(0, -0.1, 0.1);
      glTexCoord2f(1, 0);
      glVertex3f(2.5, -0.1, 0.1);
      glTexCoord2f(1, 1);
      glVertex3f(2.5, 0.1, 0.1);
      
      glTexCoord2f(0, 1);
      glVertex3f(0, 0.1, 0.1);
      glTexCoord2f(0, 0);
      glVertex3f(0, 0.1, -0.1);
      glTexCoord2f(1, 0);
      glVertex3f(2.5, 0.1, -0.1);
      glTexCoord2f(1, 1);
      glVertex3f(2.5, 0.1, 0.1);

      glTexCoord2f(0, 1);
      glVertex3f(0, 0.1, -0.1);
      glTexCoord2f(0, 0);
      glVertex3f(0, -0.1, -0.1);
      glTexCoord2f(1, 0);
      glVertex3f(2.5, -0.1, -0.1);
      glTexCoord2f(1, 1);
      glVertex3f(2.5, 0.1, -0.1);

      glTexCoord2f(0, 1);
      glVertex3f(0, -0.1, 0.1);
      glTexCoord2f(0, 0);
      glVertex3f(0, -0.1, -0.1);
      glTexCoord2f(1, 0);
      glVertex3f(2.5, -0.1, -0.1);
      glTexCoord2f(1, 1);
      glVertex3f(2.5, -0.1, 0.1);

      glTexCoord2f(0, 1);
      glVertex3f(2.5, -0.1, 0.1);
      glTexCoord2f(0, 0);
      glVertex3f(2.5, 0.1, 0.1);
      glTexCoord2f(1, 0);
      glVertex3f(2.5, 0.1, -0.1);
      glTexCoord2f(1, 1);
      glVertex3f(2.5, -0.1, -0.1);
    glEnd();
    glDisable(GL_TEXTURE_2D);
       
  glPopMatrix();
}

static void ispis_teksta(int x, int y, int z, char* tekst)
{
  int len, i;
  glRasterPos3f(x, y, z);
  
  len = (int) strlen(tekst);
  for (i = 0; i < len; i++) 
  {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, tekst[i]);
  }
}

static void pravljenje_rezultata(int rezultat)
{
  int i, poz;
  poz = 0;
  for(i = 0; i < MAX_HIGHSCORES; i++)
  {
    if(rezultati[i] > rezultat)
    {
      poz = i;
    }
  }
  int pom;
  if(poz != 0)
    pom = poz + 1;
  else
    pom = poz;
  
  for(i = MAX_HIGHSCORES-1; i > pom; i--)
  {
    rezultati[i] = rezultati[i-1];
  }

  rezultati[poz] = rezultat;
}

static void ucitaj_teksture()
{
  metal = SOIL_load_OGL_texture("./Textures/metal.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  if(metal == 0)
  {
    printf("Nije ucitana prva slika\n");
    exit(0);
  }
  drvo = SOIL_load_OGL_texture("./Textures/wood.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  if(drvo == 0)
  {
    printf("Nije ucitana druga slika\n");
    exit(0);
  }
  glava = SOIL_load_OGL_texture("./Textures/sharkhead.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  if(glava == 0)
  {
    printf("Nije ucitana treca slika\n");
    exit(0);
  }
  more = SOIL_load_OGL_texture("./Textures/sea.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  if(more == 0)
  {
    printf("Nije ucitana cetvrta slika\n");
    exit(0);
  }

  start_texture = SOIL_load_OGL_texture("./Textures/start.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  if(start_texture == 0)
  {
    printf("Nije ucitana start slika\n");
    exit(0);
  }

  highscores_texture = SOIL_load_OGL_texture("./Textures/highscores.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  if(highscores_texture == 0)
  {
    printf("Nije ucitana highscore slika\n");
    exit(0);
  }

  quit_texture = SOIL_load_OGL_texture("./Textures/quit.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  if(quit_texture == 0)
  {
    printf("Nije ucitana quit slika\n");
    exit(0);
  }

  background_texture = SOIL_load_OGL_texture("./Textures/background.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
  if(background_texture == 0)
  {
    printf("Nije ucitana background slika\n");
    exit(0);
  }  
}
