/*	==================== compare ====================
	Compare priority of two customers to determine
	who has higher priority.
	   Pre  Given two customer structures
	   Post if cust1 >  cust2 return +1
	        if cust1 == cust2 return 0
	        if cust1 <  cust2 return -1
*/

int compareCust (void* cust1, void* cust2)
{
//	Local Definitions
	CUST c1;
	CUST c2;
	
//	Statements
	c1 = *(CUST*)cust1;
	c2 = *(CUST*)cust2;
	
	if (c1.serial < c2.serial)
	    return -1;
	else if (c1.serial == c2.serial)
	    return 0;
	return +1;
}	// compareCust