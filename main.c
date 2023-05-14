#include <stdlib.h>
#include <stdint.h>
#include <gtk/gtk.h>
#include <stdbool.h>
#include <math.h>

typedef struct{
    GtkWidget *widget;
    GtkWidget *grid;
    GtkWidget *button[20];
    GtkWidget *window;
}funcoes;

GtkWidget *box;

	char entrada[100]={0}, saida[100]={0};
	float resultado=0, num[10];
	bool clr=false, add=false, mult=false, divv=false, sub=false, sinX=false, cosX=false, tgX=false;
	int contador=0;

static void calcular(GtkButton *button, gpointer data){

	const gchar* text = gtk_button_get_label(button);

	if( (strcmp("+", text)==0) || (strcmp("-", text)==0) || (strcmp("/", text)==0) || (strcmp("*", text)==0) || (strcmp("=", text)==0) || (strcmp("sin", text)==0) || (strcmp("cos", text)==0)|| (strcmp("tg", text)==0)){

		num[contador] = atof(entrada);
		contador++;
		clr = true;

		if(strcmp("+",text)==0)add=true;
		if(strcmp("-",text)==0)sub=true;
		if(strcmp("/",text)==0)divv=true;
        if(strcmp("*",text)==0)mult=true;
		if(strcmp("sin",text)==0)sinX=true;
		if(strcmp("cos",text)==0)cosX=true;
		if(strcmp("tg",text)==0)tgX=true;
	}

	if(strcmp("=",text)==0){

		if(add==true){
			resultado=num[0]+num[1];
		}

		if(divv==true){
			resultado = num[0]/num[1];
		}

		if(sub==true){
			resultado=num[0]-num[1];
		}

		if(mult==true){
			resultado = num[0]*num[1];

		}
		if(sinX==true){
            resultado=sin(num[0]);
		}
		if(cosX==true){
            resultado=cos(num[0]);
		}
		if(tgX==true){
            resultado=tan(num[0]);
		}

		add = false;
		mult = false;
		divv = false;
		sub = false;
		sinX = false;
		cosX = false;
		tgX = false;

		gtk_entry_set_text(GTK_ENTRY(box), "");
		sprintf(saida, "%.2f", resultado);
		gtk_entry_set_text(GTK_ENTRY(box), saida);
		resultado = 0;
	}
	else{
		if(clr){
			memset(entrada,0,strlen(entrada));
			clr = false;
		}else{
			strncat(entrada,text, 1);
		}

			strncat(saida,text, 1);
			gtk_entry_set_text(GTK_ENTRY(box), saida);
	}

	if(strcmp("AC",text)==0){

		gtk_entry_set_text(GTK_ENTRY(box), "");
		memset(entrada,0,strlen(entrada));
		memset(saida,0,strlen(saida));
		contador = 0;
		int x = 100;

		for(int i=0; i<x; i++){
				num[i] = 0;
		}
		add = false;
		mult = false;
		divv = false;
		sub = false;
	}
}

static void ui(GtkApplication *app, gpointer user_data){
	
	funcoes widget;

    //Cria o janela
	widget.window = gtk_application_window_new(app);
	gtk_window_set_position(GTK_WINDOW(widget.window),GTK_WIN_POS_CENTER);
	gtk_window_set_title(GTK_WINDOW(widget.window),"Calculadora");
	gtk_window_set_default_size(GTK_WINDOW(widget.window), 200, 200);
	gtk_container_set_border_width(GTK_CONTAINER(widget.window),10);

    //Cria o grid
	widget.grid = gtk_grid_new();
	gtk_container_add(GTK_CONTAINER(widget.window),widget.grid);

    //Cria o display
	box = gtk_entry_new();
	gtk_editable_set_editable(GTK_EDITABLE(box), FALSE);

    //Cria os botoes
    widget.button[0] = gtk_button_new_with_label("0");
    widget.button[1] = gtk_button_new_with_label("1");
    widget.button[2] = gtk_button_new_with_label("2");
    widget.button[3] = gtk_button_new_with_label("3");
    widget.button[4] = gtk_button_new_with_label("4");
    widget.button[5] = gtk_button_new_with_label("5");
    widget.button[6] = gtk_button_new_with_label("6");
    widget.button[7] = gtk_button_new_with_label("7");
    widget.button[8] = gtk_button_new_with_label("8");
    widget.button[9] = gtk_button_new_with_label("9");
    widget.button[10] = gtk_button_new_with_label("AC");
    widget.button[11] = gtk_button_new_with_label(",");
    widget.button[12] = gtk_button_new_with_label("=");
    widget.button[13] = gtk_button_new_with_label("+");
    widget.button[14] = gtk_button_new_with_label("-");
    widget.button[15] = gtk_button_new_with_label("*");
    widget.button[16] = gtk_button_new_with_label("/");
    widget.button[17] = gtk_button_new_with_label("sin");
    widget.button[18] = gtk_button_new_with_label("cos");
    widget.button[19] = gtk_button_new_with_label("tg");

    //Coloca os botoes e o display no app em formato de grid
    gtk_grid_attach(GTK_GRID(widget.grid),box,0,0,6,1);

    gtk_grid_attach(GTK_GRID(widget.grid),widget.button[13],0,1,1,1);
    gtk_grid_attach(GTK_GRID(widget.grid),widget.button[14],1,1,1,1);
    gtk_grid_attach(GTK_GRID(widget.grid),widget.button[15],2,1,1,1);
    gtk_grid_attach(GTK_GRID(widget.grid),widget.button[16],3,1,1,1);

    gtk_grid_attach(GTK_GRID(widget.grid),widget.button[7],0,2,1,1);
    gtk_grid_attach(GTK_GRID(widget.grid),widget.button[8],1,2,1,1);
    gtk_grid_attach(GTK_GRID(widget.grid),widget.button[9],2,2,1,1);
    gtk_grid_attach(GTK_GRID(widget.grid),widget.button[17],3,2,1,1);

    gtk_grid_attach(GTK_GRID(widget.grid),widget.button[4],0,3,1,1);
    gtk_grid_attach(GTK_GRID(widget.grid),widget.button[5],1,3,1,1);
    gtk_grid_attach(GTK_GRID(widget.grid),widget.button[6],2,3,1,1);
    gtk_grid_attach(GTK_GRID(widget.grid),widget.button[18],3,3,1,1);

    gtk_grid_attach(GTK_GRID(widget.grid),widget.button[1],0,4,1,1);
    gtk_grid_attach(GTK_GRID(widget.grid),widget.button[2],1,4,1,1);
    gtk_grid_attach(GTK_GRID(widget.grid),widget.button[3],2,4,1,1);
    gtk_grid_attach(GTK_GRID(widget.grid),widget.button[19],3,4,1,1);

    gtk_grid_attach(GTK_GRID(widget.grid),widget.button[0],0,5,1,1);
    gtk_grid_attach(GTK_GRID(widget.grid),widget.button[11],1,5,1,1);
    gtk_grid_attach(GTK_GRID(widget.grid),widget.button[10],2,5,1,1);
    gtk_grid_attach(GTK_GRID(widget.grid),widget.button[12],3,5,1,1);

    //Cria os eventos
    g_signal_connect(widget.button[0],"clicked",G_CALLBACK(calcular),NULL);
    g_signal_connect(widget.button[1],"clicked",G_CALLBACK(calcular),NULL);
    g_signal_connect(widget.button[2],"clicked",G_CALLBACK(calcular),NULL);
    g_signal_connect(widget.button[3],"clicked",G_CALLBACK(calcular),NULL);
    g_signal_connect(widget.button[4],"clicked",G_CALLBACK(calcular),NULL);
    g_signal_connect(widget.button[5],"clicked",G_CALLBACK(calcular),NULL);
    g_signal_connect(widget.button[6],"clicked",G_CALLBACK(calcular),NULL);
    g_signal_connect(widget.button[7],"clicked",G_CALLBACK(calcular),NULL);
    g_signal_connect(widget.button[8],"clicked",G_CALLBACK(calcular),NULL);
    g_signal_connect(widget.button[9],"clicked",G_CALLBACK(calcular),NULL);
    g_signal_connect(widget.button[10],"clicked",G_CALLBACK(calcular),NULL);
    g_signal_connect(widget.button[11],"clicked",G_CALLBACK(calcular),NULL);
    g_signal_connect(widget.button[12],"clicked",G_CALLBACK(calcular),NULL);
    g_signal_connect(widget.button[13],"clicked",G_CALLBACK(calcular),NULL);
    g_signal_connect(widget.button[14],"clicked",G_CALLBACK(calcular),NULL);
    g_signal_connect(widget.button[15],"clicked",G_CALLBACK(calcular),NULL);
    g_signal_connect(widget.button[16],"clicked",G_CALLBACK(calcular),NULL);
    g_signal_connect(widget.button[17],"clicked",G_CALLBACK(calcular),NULL);
    g_signal_connect(widget.button[18],"clicked",G_CALLBACK(calcular),NULL);
    g_signal_connect(widget.button[19],"clicked",G_CALLBACK(calcular),NULL);
	gtk_widget_show_all(widget.window);
}


int main(int argc, char **argv){
	GtkApplication *app;

	//Inicializa e Aloca o App
    gtk_init(&argc, &argv);
	int status;
	app = gtk_application_new("org.gtk.calculator", G_APPLICATION_DEFAULT_FLAGS);
	g_signal_connect(app,"activate", G_CALLBACK(ui), NULL);
	status = g_application_run(G_APPLICATION(app), argc, argv);

	//Desaloca o app
	g_object_unref(app);

return status;
}
