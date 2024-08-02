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
							 // Fonksiyon 1: Önce düğümün verisini yazdırır, ardından sonraki düğüme geçer. Çıktı: Baştan sona doğru sıralı.
	
	if(p != NULL){
		
		printf("%d ", p -> data);
		Display(p -> next);
	}
	
}


void Display(struct node *p){ // RECURSIVE FUNCTION 2
							 // Fonksiyon 2: Önce sonraki düğüme geçer, ardından dönüşte düğümün verisini yazdırır. Çıktı: Sondan başa doğru ters sıralı.
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

