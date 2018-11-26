#include "funkcije.c"

static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);
static void on_display(void);
static void on_timer(int value);
static void on_special(int key, int x, int y);

/* funkcija koja pokrece igru */
static void start();
/* funkcija za inicijalizaciju parametara pre crtanja cekica */
static void inicijalizacija_cekica(int x, int y, int z);
/* funkcija koja iscrtava meni */
static void menu_part();
/* funckija koja iscrtava elemente igre */
static void game_part();
/* funkcija koja pokazuje highscore */
static void highscores_part();

static void proba()
{
  gluLookAt(8 * cos(theta) * cos(phi), 8 * sin(theta), 8 * cos(theta) * sin(phi), 0, 0, 0, 0, 1, 0);
  glShadeModel(GL_SMOOTH);
  glDisable(GL_LIGHTING);
  glEnable(GL_TEXTURE_2D);
    glColor3f(0.3, 0.3, 0.3);
    //iscrtava se glava cekica
    glPushMatrix();
    glDisable(GL_LIGHTING);
    //translira se na zeljnu poziciju
    //glTranslatef(x, y+0.2, z);
    
    //rotira se za 45 stepeni ceo cekic
    glRotatef(-45, 0, 1, 0);
    //na osnovu parametara translira se u odnosu na mesto gde treba da udari
    glTranslatef(rotacija_cekica_x, rotacija_cekica_y, 0);
    glRotatef(ugao_cekica, 0, 0, 1);
    
    //glDisable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
    glColor3f(1, 1, 1);
    //iscrtava se glava cekica
    glBegin(GL_QUADS);
      /* gornje zarubljenje */
      glBindTexture(GL_TEXTURE_2D, metal);
      glNormal3f(0, 1, 0);
      glTexCoord2f(0, 1); 
      glVertex3f(-0.45, 0.7, 0.45);
      glTexCoord2f(0, 0); 
      glVertex3f(0.45, 0.7, 0.45);
      glTexCoord2f(1, 0); 
      glVertex3f(0.45, 0.7, -0.45);
      glTexCoord2f(1, 1); 
      glVertex3f(-0.45, 0.7, -0.45);
      
      glNormal3f(0, 1, 1);
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
    
    glBegin(GL_QUADS);
      glBindTexture(GL_TEXTURE_2D, drvo);
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
    glEnable(GL_LIGHTING);
       
  glPopMatrix();
}

int main(int argc, char **argv)
{
  /* Parametri svetla i podrazumevanog materijala */
  GLfloat light_ambient[] = { 0.1, 0.1, 0.1, 1 };
  GLfloat light_diffuse[] = { 0.7, 0.7, 0.7, 1 };
  GLfloat light_specular[] = { 0.9, 0.9, 0.9, 1 };

  GLfloat ambient_coeffs[] = { 0.3, 0.7, 0.3, 1 };
  GLfloat diffuse_coeffs[] = { 0.2, 1, 0.2, 1 };
  GLfloat specular_coeffs[] = { 1, 1, 1, 1 };
  GLfloat shininess = 30;

  /* Inicijalizuje se GLUT. */
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

  /* Kreira se prozor. */
  glutInitWindowSize(1300, 760);
  glutInitWindowPosition(100, 100);
  glutCreateWindow(argv[0]);

  /* Registruju se callback funkcije. */
  glutKeyboardFunc(on_keyboard);
  glutReshapeFunc(on_reshape);
  glutDisplayFunc(on_display);
  glutSpecialFunc(on_special);

  /*inicijalizacija globalnih promenjivih */

  phi = 1.57;
  theta = 0.76;
  delta_phi = pi / 90;
  delta_theta = pi / 90;

  int i;

  for (i = 0; i<9; i++)
    height_array[i] = -0.01;

  for(i = 0; i < MAX_HIGHSCORES; i++)
    rezultati[i] = 0;

  ucitaj_teksture();

  /* Obavlja se OpenGL inicijalizacija. */
  glClearColor(1, 1, 1, 0);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_NORMALIZE);
  glEnable(GL_LIGHTING);

  /* Postavljaju se svojstva prvog svetla */
  glEnable(GL_LIGHT0);

  glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

  /* Postavljaju se svojstva materijala */
  glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs);
  glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
  glMaterialf(GL_FRONT, GL_SHININESS, shininess);
  glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, 1);
  glEnable(GL_COLOR_MATERIAL);
  /* Program ulazi u glavnu petlju. */
  glutMainLoop();

  return 0;
}

static void on_special(int key, int x, int y)
{
  switch(key)
  {
    case GLUT_KEY_DOWN:
      if(meni_odabir == 0)
      {
        if(meni_highlight < 3)
        {
          meni_highlight+=1;
        }
      }
      break;

    case GLUT_KEY_UP:
      if(meni_odabir == 0)
      {
        if(meni_highlight > 1)
        {
          meni_highlight-=1;
        }
      }
      break;
  }
  glutPostRedisplay();
}

static void on_keyboard(unsigned char key, int x, int y)
{
  switch (key) {
    /*kada se pritisne ESC */
    case 27:
      if(meni_odabir == 1)
      {
        //printf("OK\n");
        meni_odabir = 0;
        meni_highlight = 0;
        pravljenje_rezultata(skor-1);
        skor = 1;
        glutPostRedisplay();
      }else if(meni_odabir == 2)
      {
        meni_odabir = 0;
        meni_highlight = 0;
      }else if(meni_odabir == 0)
      {
        int i;
        for(i = 1; i <=MAX_HIGHSCORES; i++)
        {
          printf("%d. %d\n", i, rezultati[i-1]);
        }
        exit(0);
      }

    /* kada se pritisne ENTER */
    case 13:
      if(meni_odabir == 0)
      {
        start();
        meni_odabir = meni_highlight;
      }
      glutPostRedisplay();
      break;

    case '1':
      provera_pogotka = 1;
      if(provera_pogotka == rand_choose)
        skor += 5;
      if(crtanje_cekica == 2)
      {
        crtanje_cekica = 3;
        inicijalizacija_cekica(-2, 2, 2);
      }
      break;
    case '2':
      provera_pogotka = 2;
      if(provera_pogotka == rand_choose)
        skor += 5;
      if(crtanje_cekica == 2)
      { 
        crtanje_cekica = 3;
        inicijalizacija_cekica(0, 2, 2);
      }
      break;
    case '3':
      provera_pogotka = 3;
      if(provera_pogotka == rand_choose)
        skor += 5;
      if(crtanje_cekica == 2)
      { 
        crtanje_cekica = 3;
        inicijalizacija_cekica(2, 2, 2);
      }
      break;
    case '4':
      provera_pogotka = 4;
      if(provera_pogotka == rand_choose)
        skor += 5;
      if(crtanje_cekica == 2)
      { 
        crtanje_cekica = 3;
        inicijalizacija_cekica(-2, 2, 0);
      }
      break;
    case '5':
      provera_pogotka = 5;
      if(provera_pogotka == rand_choose)
        skor += 5;
      if(crtanje_cekica == 2)
      { 
        crtanje_cekica = 3;
        inicijalizacija_cekica(0, 2, 0);
      }
      break;
    case '6':
      provera_pogotka = 6;
      if(provera_pogotka == rand_choose)
        skor += 5;
      if(crtanje_cekica == 2)
      { 
        crtanje_cekica = 3;
        inicijalizacija_cekica(2, 2, 0);
      }
      break;
    case '7':
      provera_pogotka = 7;
      if(provera_pogotka == rand_choose)
        skor += 5;
      if(crtanje_cekica == 2)
      { 
        crtanje_cekica = 3;
        inicijalizacija_cekica(-2, 2, -2);
      }
      break;
    case '8':
      provera_pogotka = 8;
      if(provera_pogotka == rand_choose)
        skor += 5;
      if(crtanje_cekica == 2)
      { 
        crtanje_cekica = 3;
        inicijalizacija_cekica(0, 2, -2);
      }
      break;
    case '9':
      provera_pogotka = 9;
      if(provera_pogotka == rand_choose)
        skor += 5;
      if(crtanje_cekica == 2)
      { 
        crtanje_cekica = 3;
        inicijalizacija_cekica(2, 2, -2);
      }
      break;

    case 'a':
      phi += delta_phi;
      if(phi > 2 * pi) {
        phi -= 2 * pi;
      } else if(phi < 0) {
        phi += 2 * pi;
      }
      glutPostRedisplay();
      break;
    case 'd':
      phi -= delta_phi;
      if(phi > 2 * pi) {
        phi -= 2 * pi;
      } else if(phi < 0) {
        phi += 2 * pi;
      }
      glutPostRedisplay();
      break;
    case 's':
      theta -= delta_theta;
      if(theta < -(pi / 2 - pi / 180)) {
        theta = -(pi / 2 - pi / 180);
      }
      glutPostRedisplay();
      break;
    case 'w':
        theta += delta_theta;
        if (theta > pi / 2 - pi / 180) {
            theta = pi / 2 - pi / 180;
        }      
        glutPostRedisplay();
      break;      
  }
}

static void on_timer(int value)
{
  if(value != 0)
    return;

  if(animation_ongoing)
  {
    
    if(crtanje_cekica == 3)
    {
      brzina_cekica -= 15;
      if(brzina_cekica <= 10)
        brzina_cekica = 10;
      glutTimerFunc(brzina_cekica, on_timer, 0);

      /* uvecavaju se parametri koji sluze za iscrtavanja cekica */
      if(ugao_cekica == 0)
        ugao_cekica = 0;
      else
        ugao_cekica += 5;
      
      if(rotacija_cekica_x <= 0 && rotacija_cekica_y <= 0)
      {
        usleep(200);
        crtanje_cekica = 1;
      }else{
        rotacija_cekica_x -= 0.1;
        rotacija_cekica_y -= 0.1;
      }
    }else if(crtanje_cekica == 2){
      /* uvecava se parametar koji sluzi za iscrtavanje dugmeta */
      glutTimerFunc(brzina_dugmica, on_timer, 0);

      animation_parameter += 0.1;
      if(animation_parameter > 1.0)
      {
        animation_parameter = 1.0;
        animation_ongoing = 0;
      }
    }else if(crtanje_cekica == 1)
    {
      /* umanjuje se parametar koji sluzi za iscrtavanje dugmeta */
      glutTimerFunc(brzina_dugmica, on_timer, 0);

      animation_parameter -= 0.1;
      if(animation_parameter < -0.01)
      {
        animation_parameter = -0.01;
        animation_ongoing = 0;
        start();
      }
    }
  }
  glutPostRedisplay(); 
}     

static void on_display(void)
{
  /* Pozicija svetla (u pitanju je beskonacno daleko svetlo). */
  GLfloat light_position[] = {1, 1, 1, 0};

  /* Brise se prethodni sadrzaj prozora. */
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  /* Inicijalizuje se matrica transformacije. */
  glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();

  //proba();

  
  if(meni_odabir == 0)
  {
    menu_part();
  }else if(meni_odabir == 1)
  {
    game_part();
  }else if(meni_odabir == 2)
  {
    highscores_part();
  }else if(meni_odabir == 3)
  {
    exit(0);
  }
  
  
  glutSwapBuffers();
}

static void on_reshape(int width, int height)
{
  /* Podesava se viewport. */
  glViewport(0, 0, width, height);

  /* Podesava se projekcija. */
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60, (float) width / height, 1, 100);
  glutPostRedisplay();
}

static void start()
{
    animation_ongoing = 1;
    animation_parameter = -0.01;
    reset();
    srand(clock());
    rand_choose = rand() % 9 + 1;
    crtanje_cekica = 2;
    glutTimerFunc(brzina_dugmica, on_timer, 0);
}


static void inicijalizacija_cekica(int x, int y, int z)
{
  animation_ongoing = 1;
  cekic_x = x;
  cekic_y = y;
  cekic_z = z;
  ugao_cekica = -90;
  rotacija_cekica_x = 1.8;
  rotacija_cekica_y = 1.8;
  brzina_cekica = 40;
  glutTimerFunc(brzina_cekica, on_timer, 0);
}

static void menu_part()
{
  /* pogled kamere */
  gluLookAt(0, 0, 7, 0, 0, 0, 0, 1, 0);
  glShadeModel(GL_FLAT);

  /* iscrtavanje menija */
  glDisable(GL_LIGHTING);
  draw_background();
  glEnable(GL_TEXTURE_2D);
  glPushMatrix();
    /* polje "start" */
    glPushMatrix();
      glTranslatef(0, 2, 0);
      
      if(meni_highlight == 1)
        glColor3f(0, 0, 1);
      else
        glColor3f(1, 0, 0);
      
      glBindTexture(GL_TEXTURE_2D, start_texture);
      glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0); 
        glVertex3f(-2, -0.5, 0);
        glTexCoord2f(1, 0);
        glVertex3f(2, -0.5, 0);
        glTexCoord2f(1, 1);
        glVertex3f(2, 0.5, 0);
        glTexCoord2f(0, 1);
        glVertex3f(-2, 0.5, 0);
      glEnd();

      glTranslatef(0, 0, -0.22);
      glScalef(4, 1, 0.5);
      glColor3f(1, 1, 1);
      glutWireCube(1);
    glPopMatrix();

    /* polje highscores */
    glPushMatrix();
      
      if(meni_highlight == 2)
        glColor3f(0, 0, 1);
      else
        glColor3f(1, 0, 0);

      glBindTexture(GL_TEXTURE_2D, highscores_texture);
      glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0); 
        glVertex3f(-2, -0.5, 0);
        glTexCoord2f(1, 0);
        glVertex3f(2, -0.5, 0);
        glTexCoord2f(1, 1);
        glVertex3f(2, 0.5, 0);
        glTexCoord2f(0, 1);
        glVertex3f(-2, 0.5, 0);
      glEnd();

      glTranslatef(0, 0, -0.22);
      glScalef(4, 1, 0.5);
      glColor3f(1, 1, 1);
      glutWireCube(1);
    glPopMatrix();

    /* polje exit */
    glPushMatrix();
      glTranslatef(0, -2, 0);
      
      if(meni_highlight == 3)
        glColor3f(0, 0, 1);
      else
        glColor3f(1, 0, 0);
      
      glBindTexture(GL_TEXTURE_2D, quit_texture);
      glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0); 
        glVertex3f(-2, -0.5, 0);
        glTexCoord2f(1, 0);
        glVertex3f(2, -0.5, 0);
        glTexCoord2f(1, 1);
        glVertex3f(2, 0.5, 0);
        glTexCoord2f(0, 1);
        glVertex3f(-2, 0.5, 0);
      glEnd();
      
      glTranslatef(0, 0, -0.22);
      glScalef(4, 1, 0.5);
      glColor3f(1, 1, 1);
      glutWireCube(1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
  glPopMatrix();
}

static void game_part()
{
  /* pogled kamere */
  gluLookAt(8 * cos(theta) * cos(phi), 8 * sin(theta), 8 * cos(theta) * sin(phi), 0, 0, 0, 0, 1, 0);
  glShadeModel(GL_SMOOTH);

  draw_background();
  
  if(crtanje_cekica == 3)
  {
    if(provera_pogotka == rand_choose)
    {
      nacrtaj_cekic(cekic_x, cekic_y, cekic_z);
    }
  }
  
  podizanje_dugmeta(rand_choose);
  //draw_debug_system(0, 0, 0);
  draw_board();
  draw_button(-2, 2, height_array[0]);
  draw_button( 0, 2, height_array[1]);
  draw_button( 2, 2, height_array[2]);

  draw_button(-2, 0, height_array[3]);
  draw_button(0, 0, height_array[4]);
  draw_button(2, 0, height_array[5]);

  draw_button(-2, -2, height_array[6]);
  draw_button(0, -2, height_array[7]);
  draw_button(2, -2, height_array[8]);
}

static void highscores_part()
{
   /* pogled kamere */
  gluLookAt(0, 0, 7, 0, 0, 0, 0, 1, 0);
  glShadeModel(GL_FLAT);
  glDisable(GL_LIGHTING);

  draw_background();
  
  /* iscrtavanje menija */
  glPushMatrix();
    glPushMatrix();
      glTranslatef(0, 2.25, 0);
      glScalef(4, 0.5, 0.5);
      glColor3f(1, 1, 1);
      glutWireCube(1);
      glColor3f(1, 0, 0);
      glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
      glTranslatef(0, 1.75, 0);
      glScalef(4, 0.5, 0.5);
      glColor3f(1, 1, 1);
      glutWireCube(1);
      glColor3f(1, 0, 0);
      glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
      glTranslatef(0, 1.25, 0);
      glScalef(4, 0.5, 0.5);
      glColor3f(1, 1, 1);
      glutWireCube(1);
      glColor3f(1, 0, 0);
      glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
      glTranslatef(0, 0.75, 0);
      glScalef(4, 0.5, 0.5);
      glColor3f(1, 1, 1);
      glutWireCube(1);
      glColor3f(1, 0, 0);
      glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
      glTranslatef(0, 0.25, 0);
      glScalef(4, 0.5, 0.5);
      glColor3f(1, 1, 1);
      glutWireCube(1);
      glColor3f(1, 0, 0);
      glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
      glTranslatef(0, -0.25, 0);
      glScalef(4, 0.5, 0.5);
      glColor3f(1, 1, 1);
      glutWireCube(1);
      glColor3f(1, 0, 0);
      glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
      glTranslatef(0, -0.75, 0);
      glScalef(4, 0.5, 0.5);
      glColor3f(1, 1, 1);
      glutWireCube(1);
      glColor3f(1, 0, 0);
      glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
      glTranslatef(0, -1.25, 0);
      glScalef(4, 0.5, 0.5);
      glColor3f(1, 1, 1);
      glutWireCube(1);
      glColor3f(1, 0, 0);
      glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
      glTranslatef(0, -1.75, 0);
      glScalef(4, 0.5, 0.5);
      glColor3f(1, 1, 1);
      glutWireCube(1);
      glColor3f(1, 0, 0);
      glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
      glTranslatef(0, -2.25, 0);
      glScalef(4, 0.5, 0.5);
      glColor3f(1, 1, 1);
      glutWireCube(1);
      glColor3f(1, 0, 0);
      glutSolidCube(1);
    glPopMatrix();
}

