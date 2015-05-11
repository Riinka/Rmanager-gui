#include <stdlib.h>
#include <gtk/gtk.h>



int main(int argc,char **argv)
{
    GtkWidget* pWindow;
    const gchar* sTitre;
    gint sLargeur;
    gint sHauteur;
    gint sPosition_y;
    gint sPosition_x;
    GtkWidget *pTable;



    gtk_init(&argc,&argv);

    pWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    /* Personnalisation de la Fenêtre */

    // Titre
    gtk_window_set_title(GTK_WINDOW(pWindow), "The library of Arnouville");
    // Taille
    gtk_window_set_default_size(GTK_WINDOW(pWindow), 260, 40);
    // Position
    gtk_window_set_position(GTK_WINDOW (pWindow), GTK_WIN_POS_CENTER);


    g_signal_connect(G_OBJECT(pWindow), "destroy", G_CALLBACK(gtk_main_quit), NULL);




    /* Creation et insertion de la table 3 lignes 2 colonnes */
    pTable=gtk_table_new(3,2,TRUE);
    gtk_container_add(GTK_CONTAINER(pWindow), GTK_WIDGET(pTable));






    /* Affichage des Informations */


    printf("\n-------\nFenetre\n------- \n \nTitre: %s \nTaille: %d x %d \nPosition: %dy %dx\nIcone: ", sTitre, sLargeur, sHauteur, sPosition_y, sPosition_x);




    gtk_widget_show_all(pWindow);

    /* Modification de la Fenêtre */



    printf("\n \n------------\nModification\n------------\n");

    sPosition_y = 200;
    sPosition_x = 200;

    // Position
    gtk_window_move(GTK_WINDOW(pWindow), sPosition_x, sPosition_y);
    printf("\nNouveau positionnement: %d x %d", sPosition_y, sPosition_x);



    sLargeur = 460;
    sHauteur = 240;

    // Taille
    gtk_window_resize(GTK_WINDOW(pWindow), sLargeur, sHauteur);
    printf("\nNouvelle taille: %d x %d", sHauteur, sLargeur);



    // Maximiser
    gtk_window_maximize(GTK_WINDOW(pWindow));
    printf("\nMaximiser");


    // Restaurer
    gtk_window_unmaximize(GTK_WINDOW(pWindow));
    printf("\nRestaurer");

    gtk_main();

    return EXIT_SUCCESS;
}



