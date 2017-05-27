#include <stdio.h>
#include <stdlib.h>

int numberOfLines(void){
	FILE*fp;
	fp=fopen("flowerSalesDB_October2011.txt", "r");
	int n=0, ch;  				// This function increment n by 1 every time when file reaches
	while (!feof(fp)){			// new line character. Variable "n" should have
		ch=fgetc(fp);			// started from 1 (cause there is no '\n' for the first line), but
		if (ch=='\n'){			// due to the fact there is extra empty last line in the file, I started from 0.
			n++;
		}
	}
fclose(fp);
return n;
}

typedef struct {				// By making this structure, we can define types of every column in the file
 int id;						// that stores various data into a single item.
 int dd;
 int qty;
 char type[81];
 double total_cost;
 char arrangement[81];			// I gave the strings the size of 81 by default, cause I think it is more than enough.
 char payment[81];
 int delivery;
 char courier[81];
} shop;




int main()
{ while(1<2){					// this condition will keep program running, so we can enter new date each time.
    setvbuf(stdout, NULL, _IONBF, 0);
    FILE*fp;
    fp=fopen("flowerSalesDB_October2011.txt", "r"); // I could have made a function for this, but  since we
    												// use it once at the beginning, I think it would have been extra.


    // I initialized strings in that way in order to compare them with the strings stored in the array of struct elements.
    // In addition, I used pointers, because I will not modify these strings, I will use them only to compare with other strings.
    int i, dd, orders=0, qty=0, gifts=0, bouquets=0, numdelivery=0, costdelivery=0;
    int numazat=0, numshapaghat=0, numqanat_agha=0, max=0;
    double total_cost=0, costqiwi=0, costcash=0, costweb_money=0, costpaypal=0, costyandex_money=0, costEpay_Kazkom=0, costhalyq_bank=0;
    char *g[255], *gift="gift", *small_bouquet="small_bouquet",*big_bouquet="big_bouquet", *pickup="pickup";
    char *qanat_agha="qanat_agha", *shapaghat="shapaghat", *azat="azat", *most="no one";
    char *qiwi="qiwi", *Qiwi="Qiwi", *cash="cash", *web_money="web_money",*paypal="paypal";
    char *yandex_money="yandex_money",*Epay_Kazkom="Epay_Kazkom",*halyq_bank="halyq_bank";


    //declared an array of type shop with size equal to the number of lines in the file.
    shop MillionRoses[numberOfLines()];

    	//stored data in an array of struct elements
    	for (i=0; i<numberOfLines(); i++){
    		fscanf(fp, "%i %i %i %s %lf %s %s %i %s ", &MillionRoses[i].id, &MillionRoses[i].dd, &MillionRoses[i].qty, &MillionRoses[i].type, &MillionRoses[i].total_cost, &MillionRoses[i].arrangement, &MillionRoses[i].payment, &MillionRoses[i].delivery, &MillionRoses[i].courier);
    		}
    	fclose(fp);
    	printf("Enter the day of the month\n");
    	scanf("%i", &dd);

    	// We enter the day(integer) and then check whether it is in the range or not.
    	// If it is not in the range it will exit the while loop.(see line 165)
    	if ((dd>=1) && (dd<=31)){
    		for (i=0; i<numberOfLines(); i++){

    			// If entered date is equal to date element in structure, then orders must increment by 1.
    			// Quantity of individual flowers must also increase by the value in quantity element of structure.
    			if (MillionRoses[i].dd==dd){
    				orders++;
    				qty+=MillionRoses[i].qty;

    			//function strcmp compares two strings, and if they are identical it returns 0.
    			//As before, we increment the number of bouquets when there are any bouquets in the type element.
    			if((strcmp(MillionRoses[i].type, small_bouquet) == 0)||(strcmp(MillionRoses[i].type, big_bouquet) == 0)){
    					bouquets=bouquets+1;
    					}

    			//I used the array g[255] in order to print list of gifts for a certain day.
    			//As before, if the following condition is true, we give to the array g[gifts] the  element of type arrangement .
    			//Then, we increment the number of gifts.
    			if (strcmp(MillionRoses[i].type, gift) == 0){
    				g[gifts]=MillionRoses[i].arrangement;
    				gifts=1+gifts;
    				}

    			//The sum of all the cost for a certain day
    			total_cost+=MillionRoses[i].total_cost;

    			//Again, this part checks if the payment type element is equal to a certain string.
    		    //If it is equal, it take corresponding total_cost type element and add its value to a certain variable.
    			if ((strcmp(MillionRoses[i].payment, qiwi) == 0) ||(strcmp(MillionRoses[i].payment, Qiwi) == 0)){
    					costqiwi+=MillionRoses[i].total_cost;
    					} else if (strcmp(MillionRoses[i].payment, cash) == 0){
    						costcash+=MillionRoses[i].total_cost;
    					} else if (strcmp(MillionRoses[i].payment, web_money) == 0){
    						costweb_money+=MillionRoses[i].total_cost;
    					} else if (strcmp(MillionRoses[i].payment, paypal) == 0){
    						costpaypal+=MillionRoses[i].total_cost;
    					} else if (strcmp(MillionRoses[i].payment, yandex_money) == 0){
    						costyandex_money+=MillionRoses[i].total_cost;
    					} else if (strcmp(MillionRoses[i].payment, Epay_Kazkom) == 0){
    						costEpay_Kazkom+=MillionRoses[i].total_cost;
    					} else if (strcmp(MillionRoses[i].payment, halyq_bank) == 0){
    						costhalyq_bank+=MillionRoses[i].total_cost;
    					}

    			// If it is not pickup, it means that there were deliveries.
    			if (strcmp(MillionRoses[i].courier, pickup) != 0){
    					numdelivery++;
    					costdelivery+=MillionRoses[i].delivery;
    					}

    			//Using the same function strcmp, we increment number of deliveries of each
    			// courier, when he deliveries something.
    			if (strcmp(MillionRoses[i].courier, qanat_agha ) == 0 ){
    					numqanat_agha++;
    					}
    			if (strcmp(MillionRoses[i].courier, shapaghat ) == 0 ){
    			  		numshapaghat++;
    					}
    			if (strcmp(MillionRoses[i].courier, azat ) == 0 ){
    				    numazat++;
    			   		}
    				}
    			}

    		//prints the requested information
    	  	printf("%i orders were placed that day\n", orders);
    	  	printf("%i individual flowers were purchased\n", qty);
    		printf("%i bouquet(s) was/were purchased\n", bouquets);
    	  	printf("%i gift(s) was/were purchased\n", gifts);

    	  	//prints every element of array, which is every gift for a certain day.
    	  	for (i=0; i<gifts; i++){
    	  		printf("%s\n", g[i]);
    	  	}
    	  	//prints the rest requested information
    	  	printf("The total cost of orders for that day is %f tenge\n\n", total_cost);
    	  	printf("Total cost broken down by payment for that day are:\n");
    	  	printf("Qiwi: %f tenge\n", costqiwi);
    	  	printf("Cash: %f tenge\n", costcash);
    	  	printf("WebMoney: %f tenge\n", costweb_money);
    	  	printf("PayPal: %f tenge\n", costpaypal);
    	  	printf("Yandex_Money: %f tenge\n", costyandex_money);
    	  	printf("Epay_Kazkom: %f tenge\n", costEpay_Kazkom);
    	  	printf("Halyk bank: %f tenge\n\n", costhalyq_bank);
    	  	printf("%i deliveri(es) was/were made\n", numdelivery);
    	 	printf("%i tenge was spent on deliveries that day\n", costdelivery);

    	 	//this part finds who made maximum number of deliveries, and whether some couriers made equal number of deliveries.
    	 	if (numazat>max) {max=numazat; most=azat;}
    	 	if (numshapaghat>max) {max=numshapaghat; most=shapaghat;}
    	 	if (numqanat_agha>max) {max=numqanat_agha; most=qanat_agha;}
    	 	if ((numqanat_agha==max) && (numshapaghat==max) && (numazat!=max)) {most="qanat_agha and shapaghat";}
    	 	if ((numqanat_agha==max) && (numshapaghat!=max) && (numazat==max)) {most="qanat_agha and azat";}
    	 	if ((numqanat_agha==max) && (numshapaghat==max) && (numazat==max)) {most="all couriers made equal number of deliveries";}
    	 	if (max==0) {most="no one";}
    	 	printf("Most deliveries made: %s\n", most);
    	    printf("Number of his/her deliveries is %i\n\n", max);
    	}

    	// if entered data(dd) is out of range, it will exit the loop and programs ends.
    	else {break;};
}
return 0;
}
