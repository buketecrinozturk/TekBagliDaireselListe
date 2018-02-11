#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>


/*****************struct olusturuyoruz *********************/ //buketecrinozturk
	struct node
	{
	    int data; 
	    struct node *next;
	};
	
	struct node *head = NULL; //ilk d�g�m� temsil etsin
	struct node *last = NULL; //son d�g�m� temsil etsin

/***************** Liste Olusturma Kismi *********************/	//buketecrinozturk
	struct node* listeOlustur(int data)
	{
	    //printf("\n olusturulan liste [%d]\n",data);
	    struct node *temp = (struct node*)malloc(sizeof(struct node)); // bellekten yer tahsis ettik
	    if(NULL == temp)
	    {
	  		printf("\n Bellek dolu!!! Yer tahsis edemedik \n");
		    return NULL;
	    }
	    temp->data = data; // temp d�g�m�n data h�cresine data'yi atiyoruz.
	    temp->next = NULL; // temp d�g�m ilk ve tek d�g�m oldugu i�in next h�cresine NULL atyyoruz.
	
	    head = last = temp; // ge�ici d�g�m ilk ve tek d�g�m oldugu i�in ayni zamanda son d�g�mde olmus oluyor
	    return temp;
	}
	/***************** Listeye Eleman Ekleme Kismi *********************/ //buketecrinozturk	
	struct node* elemanEkleme(int data, int liste_konum)
	{
	    if(NULL == head) //liste bossa
	    {
	        return (listeOlustur(data)); //liste olusturuyoruz
	    }
		
	    struct node *temp = (struct node*)malloc(sizeof(struct node));
	    if(NULL == temp)
	    {
	        printf("\n Bellek dolu!!! Yer tahsis edemedik \n");
	        return NULL;
	    }
	    temp->data = data; //gelen veriyi temp d�g�m�n�n data h�cresine ekledik 
	    temp->next = NULL; // tempden sonra gelen d�g�m belli olmadigi i�in next h�cresini NULL yaptyk 
	
	    if(liste_konum==1) //listenin sonuna eleman eklenecek ise
	    {
	        last->next = temp; // son d�g�m�n next h�cresi temp d�g�m� g�stersin
	        last = temp; //son d�g�m artik temp d�g�m oldu 
	        last->next= head; // son d�g�mde tekrar ilk d�g�m� g�sterdi 
	    }
	    else if(liste_konum==0)//listenin basina eleman eklenecek ise
	    {
	        temp->next = head;// temp d�g�m�n next h�cresi artik head  d�g�m� g�stersin
	        head = temp; //ilk d�g�m artik temp d�g�m oldu 
	        last->next=head;
	    }
	    return temp;
	}
	
	/***************** Listede Eleman Arama Kismi *********************/ //buketecrinozturk	

	struct node* elemanArama(int data, struct node **prev)
	{
	    struct node *list = head;
	    struct node *tmp = NULL;
	    bool found = false;
	    printf("\n Aranacak eleman [%d] \n",data);
	    
	  	do{
		   if(list->data == data)
	        {
	            found = true;
	            break;
	        }
	        else
	        {
	            tmp = list;
	            list = list->next;
	        }
		  }
		while(list->next != head->next); // son elemana gelene kadar d�ng� calissin

	    if(true == found)
	    {
	        if(prev) // bu k�sm� silme i�lemi i�in kullanyyoruz
	        *prev = tmp;
	        return list;
	    }
	    else
	    {
	    	return NULL;
	    }
	}
	
	/***************** Listeden Eleman Silme Kismi *********************/ //buketecrinozturk	

	int silinecekEleman(int data)
	{
	    struct node *prev = NULL;
	    struct node *del = NULL;
	
	    printf("\n ***silinecek eleman [%d] \n",data);
	
	    del = elemanArama(data,&prev);
	    if(del == NULL) 
	    {
	        return -1; // silinecek eleman bulunamadi ise
	    }
	    else
	    {
	        if(prev != NULL){ // silinecek eleman arada bir yerde ise
	            prev->next = del->next; // silinecek d�g�m�n sonrasyndaki d�g�m 
										//silinecek d�g�m�n �ncesindeki d�g�me baglandi
	            printf("\n adim1***del->data [%d] \n",del->data);
			}
	        if(del == last) // silinecek eleman sonda ise
	        {
	            last = prev; // son d�g�m artik prev d�g�m oldu
	            last->next=head; //circle link oldu�u i�in son d�g�m ilk d�g�m� g�sterdi
	            printf("\n adim2***last->data [%d] \n",last->data);

	        }
	        else if(del == head) // silinecek eleman basta ise
	        {
	            head = del->next; // head d�g�m artik bir kendinden sonra gelen d�g�m oldu.
	            last->next=head; //circle link oldu�u i�in son d�g�m de art�k yeni ilk d�g�m� g�sterdi
	            printf("\n adim3***head->next [%d] \n",head->next);

	        }
	    }
	
	    free(del);
	    del = NULL;
	
	    return 0;
	} 
	/***************** Listedeki Verileri Listeleme K�sm� *********************/ //buketecrinozturk	

	void print_list(void)
	{
	    struct node *list = head;
	 	printf("\n Listenin ilk Eleman�[%d] \n",last->next->data);
	    printf("\n Listenin son Eleman�[%d] \n",last->data);
	     printf("\n -------Listeleme Basladi------- \n");
	    while(list->next != head)
	    {
	        printf("\n [%d] \n",list->data);
	        list = list->next;
	    }
	    printf("\n [%d] \n",list->data);
	    printf("\n -------Listeleme Bitti------- \n");
	
	    return;
	}
	
	/***************** Main Kismi *********************/	

	int main(void)
{
    int i = 0, delval = 0;
    struct node *list = NULL;
	int eleman;
    //print_list();

	for(i = 5; i<10; i++)
	 	elemanEkleme(i,1);//listenin sonuna eleman ekleme
	

    for(i = 4; i>0; i--)
        elemanEkleme(i,0);//listenin basina eleman ekleme

       	int deger=9;
        list = elemanArama(deger, NULL);
        if(NULL == list)
        {
         // printf("\n Aranan deger [val = %d] bulunamadi\n",i);
        }
        else
        {
          //printf("\n Arana deger [val = %d] bulundu\n",list->data);
        }

       // print_list();// listele

       delval = silinecekEleman(deger);
       print_list();// listele      
  
    return 0;
}
