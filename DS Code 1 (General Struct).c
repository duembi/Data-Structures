struct node // NODE YAPISI BU SEKILDE TANIMLANMAKTADIR
	{ 
		int data; 
		struct node *next; 
	}; 


Display(struct Node *ptr){
	
	while(ptr != NULL){  //while(ptr != 0), while(p) SEKLINDE YAZILABILIR
	
		printf("%d", ptr -> data);
		
		ptr = ptr -> next;		
		
		
	}
	
	
}
// MAIN'DE CAGIRACAGIM ZAMAN DA display(ILK NODU GOSTEREN POINTER'IN ADI) SEKLINDE YAZ


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Display(struct node *p){ // RECURSIVE FUNCTION 1 
							 // Fonksiyon 1: �nce d���m�n verisini yazd�r�r, ard�ndan sonraki d���me ge�er. ��kt�: Ba�tan sona do�ru s�ral�.
	
	if(p != NULL){
		
		printf("%d ", p -> data);
		Display(p -> next);
	}
	
}


void Display(struct node *p){ // RECURSIVE FUNCTION 2
							 // Fonksiyon 2: �nce sonraki d���me ge�er, ard�ndan d�n��te d���m�n verisini yazd�r�r. ��kt�: Sondan ba�a do�ru ters s�ral�.
	if(p != NULL){
	
		Display(p -> next);	
		printf("%d ", p -> data);
	
	}
	
}

int main(){
	
	int A[] = {3, 5, 7, 10, 15};
	
	creat(A, 5);
	
	RDisplay(first);
	
	
}

