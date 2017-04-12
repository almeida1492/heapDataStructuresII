int compareInt(void *num1, void *num2){
	int aux1, aux2;

	aux1 = *(int*)num1;
	aux2 = *(int*)num2;

	if(aux1 < aux2){
		return -1;
	}
	else if(aux1 == aux2){
		return 0;
	}
	return +1;
}