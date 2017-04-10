/*	==================== getCust ====================
	Reads customer data from keyboard.
	   Pre  nothing
	   Post data read and returned in structure
*/

CUST* getCust (void)
{
//	Local Definitions
	CUST* cust;
	
//	Statements
	cust = (CUST*)malloc(sizeof (CUST));
	if (!cust)
	   printf("Memory overflow in getCust\n"),
	       exit (200);
	   
	printf("Enter customer id:       ");
	scanf ("%d", &cust->id);
	printf("Enter customer priority: ");
	scanf ("%d", &cust->priority);
	return cust;
}	// getCust