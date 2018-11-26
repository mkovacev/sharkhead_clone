/* Parametar animacije, fleg koji odredjuje da li je animacija u toku ili nije */
#define TIMER_ID 0
#define TIMER_INTERVAL 10
#define MAX_LEN 512
#define MAX_HIGHSCORES 10

/* niz tekstura: 0: metal, 1: drvo, 2: glava ajkule, 3: more*/
GLuint metal;
GLuint drvo;
GLuint glava;
GLuint more;
GLuint start_texture;
GLuint highscores_texture;
GLuint quit_texture;
GLuint background_texture;


/* niz za cuvanje rezultata */
int rezultati[MAX_HIGHSCORES];

float animation_parameter = -0.01;
int animation_ongoing = 0;

/* promenjiva za pracenje odabira u glavnom meniju: 1 - pokrece se igra, 2 - otvara se highscore, 
                                                    3 - izlazi iz igre */
int meni_odabir = 0;

/* promenjiva za pracenje prikaza u glavnom meniju */
int meni_highlight = 1;

/* promenjiva koje odredjuju kada se cekic iscrtava, moze da ima 3 vrednosti: prva pre prvog biranja 
   dugmeta, druga daje dozvolu i treca kada se cekic iscrtava */
int crtanje_cekica = 1;
/* promenjive koje odredjuju polozaj cekica u koordinatnom sistemu */
float cekic_x, cekic_y, cekic_z;
/* promenjive koje odredjuju rotaciju cekica pri udaranju u dugme */
float ugao_cekica, rotacija_cekica_x, rotacija_cekica_y;

const static float pi = 3.1415;

/* uglovi koji odredjuju polozaj kamere */
float phi, theta;
/* inkrementi gornjih uglova */
float delta_phi, delta_theta;
/* niz paramtara za visinu dugmica */
float height_array[9];
/* promenjiva za random odabir dugmica */
int rand_choose;

/* promenjiva koja proverava da li je pogodjeno dobro dugme */
int provera_pogotka;

/* promenjiva koja odredjuje brzinu iskakanja dugmica */
int brzina_dugmica = 50;
/* promenjiva koja odredjuje brzinu cekica */
int brzina_cekica = 50;
/* promenjiva koja belezi skor */
int skor = 1;

/* promenjiva koja prati da li je pokrenuta igra ili ne */
int game_on = 0;
/* promenjiva koja oznacava pauzu izmedju instanci podizanja dugmica i udaranja cekicem */
int hardness = 1000000;

/* funkcija za iscrtavanje 3 vektora koja polaze iz centra koordinatnog sistema */
static void draw_debug_system(float x, float y, float z);
/* funkcija za iscrtavanje pozadine */
static void draw_background();
/* funkcija za iscrtavanje table */
static void draw_board();
/* funkcija za iscrtavanje iskacuceg dugmeta */
static void draw_button(float x, float z, float height);
/* funkcija za odredjivanje dugmeta koje je izdvojeno */
static void pozicija_dugmica(int n, float h);
/* funkcija koja resetuje dugmice */
static void reset();
/* funkcija koja animira podizanje dugmeta */
static void podizanje_dugmeta(int n);

/* funkcija za crtanje cekica */
static void nacrtaj_cekic(float x, float y, float z);

/* funkcija za pisanje teksta */
static void ispis_teksta(int x, int y, int z, char* tekst);

/* funkcija za ubacivanje novog rezultata u niz */
static void pravljenje_rezultata(int rezultat);

/* funkcija za ucitavanje tekstura */
static void ucitaj_teksture();
