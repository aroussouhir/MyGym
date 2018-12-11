#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <stdio.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "dispo.h"
#include "aff.h"

void
on_buttonajout_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *combojour; 

GtkWidget *combomois; 

GtkWidget *comboyear; 

GtkWidget *spinbutton_nbplaces;

GtkWidget *labmessage;

combojour = lookup_widget(objet_graphique,"combojour");

combomois = lookup_widget(objet_graphique,"combomois");

comboyear = lookup_widget(objet_graphique,"comboyear");

labmessage = lookup_widget(objet_graphique,"labmessage");

spinbutton_nbplaces = lookup_widget(objet_graphique,"spinbutton_nbplaces");

if ( (gtk_combo_box_get_active_text(GTK_COMBO_BOX(combojour))!=NULL)&&(gtk_combo_box_get_active_text(GTK_COMBO_BOX(combomois))!=NULL)&&(gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboyear))!= NULL))
{

char jour[3];
strcpy(jour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combojour)));

char mois[3];
strcpy(mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combomois)));

char year[6];
strcpy(year,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboyear)));

int nbplaces = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_nbplaces));

if (verif2(jour,mois,year)==1)
{

FILE *f = fopen("src/disponibilite.txt","a+");

if (verif1(jour,mois,year)==1)
{
if ( f !=NULL )
{
fprintf(f,"%s %s %s %d\n",jour,mois,year,nbplaces);

gtk_label_set_text(GTK_LABEL(labmessage),"Ajout réussi.");
}
fclose(f);
}
else
gtk_label_set_text(GTK_LABEL(labmessage),"Veuillez entrer une date valide.");
}
else
gtk_label_set_text(GTK_LABEL(labmessage),"Cette date existe deja.");
}
else
gtk_label_set_text(GTK_LABEL(labmessage),"Veuillez entrer une date valide.");
}

void
on_buttonsup_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *comboboxdisp;
GtkWidget *mess_supp;
mess_supp = lookup_widget(objet_graphique,"mess_supp");

int x;

char jour[5] ;

char mois[5] ;

char year[5] ;

char places[5];

int nbplaces;

char ch1[20];

char ch[20];

comboboxdisp = lookup_widget(objet_graphique,"comboboxdisp");

if(gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxdisp))!=NULL)
{

FILE* f= fopen("src/disponibilite.txt","r");

FILE* f1= fopen("src/copie.txt","w");

strcpy(ch1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxdisp)));

if (f != NULL){

		while( fscanf(f,"%s %s %s %d\n",jour,mois,year,&nbplaces)!=EOF )
	{	
		chaine(ch,jour,mois,year,places,nbplaces);
		
			if (strcmp(ch,ch1)!=0)
                            {
				fprintf(f1,"%s %s %s %d\n",jour,mois,year,nbplaces);   
				                         
}	
}
}
fclose(f);
fclose(f1);

f= fopen("src/disponibilite.txt","w");

f1= fopen("src/copie.txt","r");


if (f1 != NULL){

		while( fscanf(f1,"%s %s %s %d\n",jour,mois,year,&nbplaces)!=EOF )
	{	
		fprintf(f,"%s %s %s %d\n",jour,mois,year,nbplaces);                               
}
}

fclose(f1);
x=remove("src/copie.txt");

gtk_list_store_clear (GTK_LIST_STORE (gtk_combo_box_get_model(comboboxdisp)));
	
	if (f != NULL){

		while( fscanf(f,"%s %s %s %d\n",jour,mois,year,&nbplaces)!=EOF )
	{	
		chaine(ch,jour,mois,year,places,nbplaces);
			
		gtk_combo_box_append_text (GTK_COMBO_BOX (comboboxdisp), _(ch));
	
}
}
fclose(f);
gtk_label_set_text(GTK_LABEL(mess_supp),"Suppression terminée.");
}
else
gtk_label_set_text(GTK_LABEL(mess_supp),"Choisir une date a supprimer.");
}

void
on_comboboxdisp_popup                  (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
}

void
on_rafresh_clicked                     (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *comboboxdisp;

FILE* f = fopen("src/disponibilite.txt","r+");

char jour[5] ;

char mois[5] ;

char year[5] ;

char places[5];

char ch[45] ;

int nbplaces ;


comboboxdisp = lookup_widget(objet_graphique,"comboboxdisp");

gtk_list_store_clear (GTK_LIST_STORE (gtk_combo_box_get_model(comboboxdisp)));	

	if (f != NULL){

		while( fscanf(f,"%s %s %s %d\n",jour,mois,year,&nbplaces)!=EOF )
	{	
		chaine(ch,jour,mois,year,places,nbplaces);
			
		gtk_combo_box_append_text (GTK_COMBO_BOX (comboboxdisp), _(ch));

}
fclose(f);
}
}

void
on_buttonmodif_clicked                 (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *comboboxdisp2;

comboboxdisp2 = lookup_widget(objet_graphique,"comboboxdisp2");

GtkWidget *combojour2; 

GtkWidget *combomois2; 

GtkWidget *comboyear2; 

GtkWidget *spinbutton_nbplaces2;

GtkWidget *labelmess2;

combojour2 = lookup_widget(objet_graphique,"combojour2");

combomois2 = lookup_widget(objet_graphique,"combomois2");

comboyear2 = lookup_widget(objet_graphique,"comboyear2");

labelmess2 = lookup_widget(objet_graphique,"labelmess2");

spinbutton_nbplaces2 = lookup_widget(objet_graphique,"spinbutton_nbplaces2");

char ch1[20];


if (gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxdisp2))!=NULL)
{
strcpy(ch1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxdisp2)));

if ( (gtk_combo_box_get_active_text(GTK_COMBO_BOX(combojour2))!=NULL)||(gtk_combo_box_get_active_text(GTK_COMBO_BOX(combomois2))!=NULL)||(gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboyear2))!=NULL)||(gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_nbplaces2))!=1))
{

char j[3]="";
char m[3]="";
char y[5]="";
int nbp=1;

if (gtk_combo_box_get_active_text(GTK_COMBO_BOX(combojour2)) != NULL)
{
strcpy(j,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combojour2)));
}

if (gtk_combo_box_get_active_text(GTK_COMBO_BOX(combomois2))!= NULL)
{
strcpy(m,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combomois2)));
}

if (gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboyear2))!= NULL)
{
strcpy(y,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboyear2)));
}

if (gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_nbplaces2))!=1);
{
nbp=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_nbplaces2));
}

int x;

char jour[5] ;
char mois[5] ;
char year[5] ;
char places[5];
int nbplaces;

char ch[20];

FILE* f= fopen("src/disponibilite.txt","r");

FILE* f1= fopen("src/copie.txt","w");

if (f != NULL)
{
		while( fscanf(f,"%s %s %s %d\n",jour,mois,year,&nbplaces)!=EOF )
	{	chaine(ch,jour,mois,year,places,nbplaces);
	
			if (strcmp(ch,ch1)!=0)
                        {
				fprintf(f1,"%s %s %s %d\n",jour,mois,year,nbplaces);                               
			}
			else
			{ 
		remplacer(jour,j,mois,m,year,y,nbplaces,nbp);
			
			  fprintf(f1,"%s %s %s %d\n",jour,mois,year,nbplaces);    	
  			}
	}
}
fclose(f);
fclose(f1);

f= fopen("src/disponibilite.txt","w");

f1= fopen("src/copie.txt","r");


if (f1 != NULL){

		while( fscanf(f1,"%s %s %s %d\n",jour,mois,year,&nbplaces)!=EOF )
	{	
		fprintf(f,"%s %s %s %d\n",jour,mois,year,nbplaces);                               
}
}
fclose(f1);
x=remove("src/copie.txt");

gtk_list_store_clear (GTK_LIST_STORE (gtk_combo_box_get_model(comboboxdisp2)));
	
	if (f != NULL){

		while( fscanf(f,"%s %s %s %d\n",jour,mois,year,&nbplaces)!=EOF )
	{	
		chaine(ch,jour,mois,year,places,nbplaces);
			
		gtk_combo_box_append_text (GTK_COMBO_BOX (comboboxdisp2), _(ch));
	
}
}
fclose(f);
gtk_label_set_text(GTK_LABEL(labelmess2),"Modification terminée.");  

}
else 
gtk_label_set_text(GTK_LABEL(labelmess2),"Saisir au moins un parametre.");
}
else
gtk_label_set_text(GTK_LABEL(labelmess2),"Choisir une date a modifier.");
}


void
on_rafresh2_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *comboboxdisp2;

comboboxdisp2 = lookup_widget(objet_graphique,"comboboxdisp2");

FILE* f = fopen("src/disponibilite.txt","r+");

char jour[5] ;

char mois[5] ;

char year[5] ;

char places[5];

char ch[45] ;

int nbplaces ;


gtk_list_store_clear (GTK_LIST_STORE (gtk_combo_box_get_model(comboboxdisp2)));	

	if (f != NULL){

		while( fscanf(f,"%s %s %s %d\n",jour,mois,year,&nbplaces)!=EOF )
	{	chaine(ch,jour,mois,year,places,nbplaces);
		
		gtk_combo_box_append_text (GTK_COMBO_BOX (comboboxdisp2), _(ch));

}
}
fclose(f);
}


void
on_buttonaff_clicked                   (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *affichage_disp;
GtkWidget *consulter_profil_kin;
GtkWidget *treeview1;

consulter_profil_kin=lookup_widget(objet_graphique,"consulter_profil_kin");

gtk_widget_destroy(consulter_profil_kin);
affichage_disp=lookup_widget(objet_graphique,"affichage_disp");
affichage_disp=create_affichage_disp();

gtk_widget_show(affichage_disp);

treeview1=lookup_widget(affichage_disp,"treeview1");

affichage(treeview1);
}


void
on_button_retour_clicked               (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *consulter_profil_kin, *affichage_disp;

affichage_disp=lookup_widget(objet_graphique,"affichage_disp");

gtk_widget_destroy(affichage_disp);
consulter_profil_kin=create_consulter_profil_kin();
gtk_widget_show(consulter_profil_kin);
}

