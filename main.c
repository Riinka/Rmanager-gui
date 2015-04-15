#include <time.h>
#include <stdlib.h>
#include <gtk/gtk.h>

void Pause(int Temps);

int main(int argc,char **argv)
{
    GtkWidget* pWindow;
    const gchar* sTitre;
    gint sLargeur;
    gint sHauteur;
    gint sPosition_y;
    gint sPosition_x;
    int icone;

    gtk_init(&argc,&argv);

    pWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    /* Personnalisation de la Fenêtre */

    // Titre
    gtk_window_set_title(GTK_WINDOW(pWindow), "The library of Arnouville");
    // Taille
    gtk_window_set_default_size(GTK_WINDOW(pWindow), 260, 40);
    // Position
    gtk_window_set_position(GTK_WINDOW (pWindow), GTK_WIN_POS_CENTER);
    // Icône
    icone = gtk_window_set_icon_from_file(GTK_WINDOW(pWindow), "icone.ico", NULL);

    g_signal_connect(G_OBJECT(pWindow), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* Récupération des Informations sur la Fenêtre */

    // Titre
    sTitre = gtk_window_get_title(GTK_WINDOW(pWindow));
    // Taille
    gtk_window_get_default_size(GTK_WINDOW(pWindow), &sLargeur, &sHauteur);
    // Position
    gtk_window_get_position(GTK_WINDOW(pWindow), &sPosition_x, &sPosition_y);

    /* Affichage des Informations */


    printf("\n-------\nFenetre\n------- \n \nTitre: %s \nTaille: %d x %d \nPosition: %dy %dx\nIcone: ", sTitre, sLargeur, sHauteur, sPosition_y, sPosition_x);

    // Icône
    if (icone == 1) // Si l'icône est Chargée
       printf("Charge! \n");

    else if (icone == 0) // Si l'icône n'est pas Chargée (impossible de l'ouvrir)
       printf("Impossible de Charger l'icone... \n");

    Pause(3);

    gtk_widget_show_all(pWindow);

    /* Modification de la Fenêtre */

    Pause(1);

    printf("\n \n------------\nModification\n------------\n");

    sPosition_y = 200;
    sPosition_x = 200;

    // Position
    gtk_window_move(GTK_WINDOW(pWindow), sPosition_x, sPosition_y);
    printf("\nNouveau positionnement: %d x %d", sPosition_y, sPosition_x);

    Pause(1);

    sLargeur = 460;
    sHauteur = 240;

    // Taille
    gtk_window_resize(GTK_WINDOW(pWindow), sLargeur, sHauteur);
    printf("\nNouvelle taille: %d x %d", sHauteur, sLargeur);

    Pause(1);

    // Maximiser
    gtk_window_maximize(GTK_WINDOW(pWindow));
    printf("\nMaximiser");
    Pause(1);

    // Restaurer
    gtk_window_unmaximize(GTK_WINDOW(pWindow));
    printf("\nRestaurer");

    gtk_main();

    return EXIT_SUCCESS;
}

void Pause(int Temps)
{
     int T1, T2;

     T1 = time(NULL);

     do
     {
          T2 = time(NULL);
     }

     while(T2-T1 != Temps);
}
