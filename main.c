#include <stdlib.h>
#include <gtk/gtk.h>

#include <time.h>
#include <stdlib.h>
#include <gtk/gtk.h>

void Pause(int Temps);

int main(int argc,char **argv)
{
    gchar* TexteConverti = NULL;
    GtkWidget* Fenetre = NULL;
    GtkWidget* Label = NULL;
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
    gtk_window_set_title(GTK_WINDOW(pWindow), "Library of Arnouville");
    // Taille
    gtk_window_set_default_size(GTK_WINDOW(pWindow), 260, 40);
    // Position
    gtk_window_set_position(GTK_WINDOW (pWindow), GTK_WIN_POS_CENTER);
    // Icône
    icone = gtk_window_set_icon_from_file(GTK_WINDOW(pWindow), "icone.ico", NULL);

    g_signal_connect(G_OBJECT(pWindow), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    //Texte

TexteConverti = g_locale_to_utf8("<span face=\"Verdana\" foreground=\"#73b5ff\" size=\"xx-large\"><b>Le site du Zéro</b></span>\n <span face=\"Verdana\" foreground=\"#39b500\" size=\"x-large\">Le tuto GTK</span>\n", -1, NULL, NULL, NULL);  //Convertion du texte avec les balises
    Label=gtk_label_new(TexteConverti); // Application de la convertion à notre label
    g_free(TexteConverti); // Libération de la mémoire

    gtk_label_set_use_markup(GTK_LABEL(Label), TRUE); // On dit que l'on utilise les balises pango

    gtk_label_set_justify(GTK_LABEL(Label), GTK_JUSTIFY_CENTER); // On centre notre texte

    gtk_container_add(GTK_CONTAINER(Fenetre), Label);  // On ajoute le label a l'interieur de 'Fenetre'

    gtk_widget_show_all(Fenetre); // On affiche 'Fenetre' et tout ce qu'il contient


    /* Récupération des Informations sur la Fenêtre */

    // Titre
    sTitre = gtk_window_get_title(GTK_WINDOW(pWindow));
    // Taille
    gtk_window_get_default_size(GTK_WINDOW(pWindow), &sLargeur, &sHauteur);
    // Position
    gtk_window_get_position(GTK_WINDOW(pWindow), &sPosition_x, &sPosition_y);

    /* Affichage des Informations */

    // On pourrait afficher ces informations dans la Fenêtre grâce à un Label mais vous les verrez dans le prochain Chapitre donc on affiche les données dans la Console
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

    sPosition_y = 500;
    sPosition_x = 200;

    // Position
    gtk_window_move(GTK_WINDOW(pWindow), sPosition_x, sPosition_y);
    printf("\nNouveau positionnement: %d x %d", sPosition_y, sPosition_x);

    Pause(1);

    sLargeur = 460;
    sHauteur = 240;

    // Taille
    gtk_window_resize(GTK_WINDOW(pWindow), sLargeur, sHauteur); // On verra le changement de Taille de la Fenêtre lorsqu'on la Restaurera
    printf("\nNouvelle taille: %d x %d", sHauteur, sLargeur);

    Pause(1);

    // Maximiser
    gtk_window_maximize(GTK_WINDOW(pWindow));
    printf("\nMaximiser");
    Pause(1);

    // Restaurer
    gtk_window_unmaximize(GTK_WINDOW(pWindow)); // On voie la Nouvelle Taille de la Fenêtre => Elle n'est plus petite comme avant
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
