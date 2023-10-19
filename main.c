#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

#include <pthread.h>
// ---------------------------------------------------------------
#define listMetodMax=32;
#define nameMetodMax=64;
//создаем идентификатор потока
	pthread_t thread;
int testpartam;
 struct sent
{
   char* str;
   struct sent* next;
};

void create_node(struct sent** h, char* info)
{
   struct sent* n = (struct sent*) malloc (sizeof(struct sent));
   struct sent* cur;
   n->str = strdup(info);
   n->next = NULL;
   if (*h == NULL)
   {      *h = n;   
    }
   else
   {      for (cur = *h; cur->next; cur = cur->next) { ; }
      cur->next = n;
   }
}
void clr_mem(struct sent* h)
{
   struct sent* tmp;
   while (h != NULL)
   {
      tmp = h;
      h = h->next;
      free(tmp->str);
      free(tmp);
   }
}
void print(struct sent* h)
{
   for (; h; h = h->next)
   {
      printf("%s ", h->str);
   }
   printf("\n");
}
// ---------------------------------------------------------------


void* threadFunc(void* thread_data){
int i;
for (i=1; i<=10; i++)	
    { sleep(1);  
      printf ("*");
    }
//завершаем поток
	pthread_exit(0);
}

// Слот выхода из программы
G_MODULE_EXPORT void onExit(GtkWidget * w) {
    gtk_main_quit();
}

//  открытие метода 
G_MODULE_EXPORT void onStartMetod(GtkWidget * w) {
	//какие то данные для потока (для примера)
	void* thread_data = NULL;
gpointer label_metod;

    //создаем поток по идентификатору thread и функции потока threadFunc
	//и передаем потоку указатель на данные thread_data
	if (pthread_create(&thread, NULL, threadFunc, thread_data))
    { printf(" поток не запущен");
    };
	
  pthread_join(thread,NULL);


GError* error = NULL;
 /* это тот волшебный объект, который сделает за нас окошко */
        GtkBuilder *builder_metod;
   /* это виджет окна */
        GtkWidget *window_metod;
       /* тут загружаем файл с интерфейсом */
        builder_metod = gtk_builder_new ();
        if (!gtk_builder_add_from_file (builder_metod, "metod.glade", &error))
        {
                /* загрузить файл не удалось */
                g_critical ("Не могу загрузить файл метода: %s", error->message);
                g_error_free (error);
        }
        label_metod = GTK_BUTTON(gtk_builder_get_object(builder_metod, "label_metod"));
        gtk_label_set_text (label_metod, "Привет, Хабр!");

       /* получаем виджет окна, чтобы его показать */
        window_metod = GTK_WIDGET (gtk_builder_get_object (builder_metod, "winmetod"));
        if (!window_metod)
        {
                /* что-то не так, наверное, ошиблись в имени */
                g_critical ("Ошибка при получении виджета окна");
        }

       gtk_widget_show (window_metod);

}



void SeeAllmetod()
{
}
gboolean TimerFunc(gpointer data)
{
    // do something
    printf(" * ");
  //  serial_counter++;
    return TRUE;
}



enum {
  COLUMN_STRING,
  COLUMN_INT,
  COLUMN_BOOLEAN,
  N_COLUMNS
};
static GtkWidget*create_window ()
{ 

// создаем список методов и читаем его ( пока из файла)
struct sent* head = NULL;
 FILE *fp;
  char str_name_metod[128];
  char name[] = "metods/metods.txt";
    int len;
  if ((fp = fopen(name, "r")) == NULL)
  {
    printf("Не удалось открыть файл");
    getchar();
    return 0;
  }
 
 while (fscanf(fp,"%s",str_name_metod)>0)
{         create_node(&head, str_name_metod);
}
 fclose(fp);

  /* это тот волшебный объект, который сделает за нас окошко */
        GtkBuilder *builder;
   /* это виджет окна */
        GtkWidget *window;
        GtkButton *button_exit;
        GtkButton *button_load_metod;
        GtkTreeView *TreeView_metod;
        GtkListStore *liststore_metod;
        GtkTreeIter iter;

        /* сюда будем складывать ошибки */
        GError* error = NULL;

        /* тут загружаем файл с интерфейсом */
        builder = gtk_builder_new ();
        if (!gtk_builder_add_from_file (builder, "electo.glade", &error))
        {
                /* загрузить файл не удалось */
                g_critical ("Не могу загрузить файл: %s", error->message);
                g_error_free (error);
        }


        /* получаем виджет окна, чтобы его показать */
        window = GTK_WIDGET (gtk_builder_get_object (builder, "windowelecto"));
        if (!window)
        {
                /* что-то не так, наверное, ошиблись в имени */
                g_critical ("Ошибка при получении виджета окна");
        }


        button_exit = GTK_BUTTON(gtk_builder_get_object(builder, "button_exit"));
        g_signal_connect(GTK_BUTTON(button_exit), "clicked",G_CALLBACK(onExit), NULL);
        button_load_metod = GTK_BUTTON(gtk_builder_get_object(builder, "button_load_metod"));
        g_signal_connect(GTK_BUTTON(button_load_metod), "clicked",G_CALLBACK(onStartMetod), NULL);

   //     g_object_unref (builder);
// создаем  "TreeView"и "liststore" для отображения методов 
        TreeView_metod  =  GTK_TREE_VIEW(gtk_builder_get_object(builder, "TreeView_metod"));  
        liststore_metod = GTK_LIST_STORE(gtk_builder_get_object(builder, "liststore_metod"));
        gtk_list_store_clear(liststore_metod);

    printf(" g_timeout_add ");
//  g_timeout_add(1000, timer_data, 0);
       g_timeout_add_seconds(1,TimerFunc,1);// в доп. параметре передаём текстовую метку для обновления

// идем по вcем записям
int len_str=2048 ; //  длинна строки для считывания данных
char str[len_str]; // буфер для считывания
 for (; head; head = head->next)
      {  gtk_list_store_append (liststore_metod, &iter);

        memset(str,0,len_str);  // обнулили строку от мусора
        strncat(str, "metods/",32);
        strncat(str,head->str,128);
        strncat(str,"/opisanie.txt",32);

         if ((fp = fopen(str, "r")) )
          {
            fgets(str,1024,fp);
            printf ("%s\r\n",str);
          } else  
        {
            printf ("file %s not open \r\n", str);
        }

     fclose(fp);


        gtk_list_store_set (liststore_metod, &iter,
                        0, head->str,
                        1, str,
                         -1);
       }
     clr_mem(head);
    return window;
}



/* это главная функция нашего приложения, которая будет выполнена первой */
int main (int argc, char *argv[])
{


        /* виджет окна */
        GtkWidget *window;
        /* запускаем GTK+ */
        gtk_init (&argc, &argv);
        /* вызываем нашу функцию для создания окна */
        window = create_window ();
       gtk_widget_show (window);

	// Обработка завершения программы
	    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

        /* передаём управление GTK+ */
        gtk_main ();

        return 0;
}


