#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
#include "aff.h"

enum
{
	JOUR,
	MOIS,
	YEAR,
	PLACES,
	COLUMNS
};

void affichage (GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;

GtkListStore *store;

char jour[3];
char mois[3];
char year[6];
char places[3];

store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" jour", renderer, "text", JOUR, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste), column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" mois", renderer, "text", MOIS, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" year", renderer, "text", YEAR, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste), column);

		renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" places", renderer, "text", PLACES, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW(liste), column);

	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

}

f = fopen("disponibilite.txt","r");

if(f==NULL)
{
	return;
}
else
{
	f = fopen("disponibilite.txt","a+");
		while(fscanf(f,"%s%s%s%s\n",jour,mois,year,places)!=EOF)
		{ 
		gtk_list_store_append (store,&iter);
		gtk_list_store_set (store, &iter, JOUR, jour, MOIS, mois, YEAR, year, PLACES, places, -1);
		}
	fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
 g_object_unref (store);
}

}















