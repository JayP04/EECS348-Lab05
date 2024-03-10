#include <stdio.h>
#include <stdlib.h>
#include <string.h>




struct value_main //defining a structure where I will store a month_key-value pair where the month_key will be a string while value will represent sales figure for that month.
{

    char month_key[100];//This will be the array to store the array of characters which will hold the month name

    double sales_val;//this is a varibale to hold the sales figures for the month

};



struct value_main monthly[12];//here I am declaring an array montly of value main to store sales data for all months
void temp_dict()//Intializing a dictionary which will intialize the monthly array.

{

    FILE *sales = fopen("input.txt", "r");//opening the given input from a text file. 
    char temp_sales[100];//Here to store the figures, intorducing temp sales to store it. 
    const char *months[] = {"January", "Febuary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};//defining a string which will contain the names of months. 
    int x = 0;//
    while (fgets (temp_sales, sizeof (temp_sales), sales) && (x < 12))//here reading lines from the file. as well as makign sure that we do not read more than 12 lines since that will do it for 12 months. 

    {//Here we will convert the string, which is representing the figures, into a float. 
    //Then, we will assign it a month name in order to do monthly representation of sales. 
    //After that we will update the sales figure which is inside the structure.

        float numberof_sales = atof(temp_sales);
        strcpy(monthly[x].month_key, months[x]);
        monthly[x].sales_val = numberof_sales;
        x++;

    }
    //finally closing the file. 
    fclose(sales);

}


//For this required output, I am defining a function which will print a report representing the sales for the year 2022 along with monlty sales.
void montly_sales_report()

{
//writing print statements to get the desired output style. 
    printf("Monthly sales report for 2022: \n\n");
    printf("%-10s %s\n", "Month", "Sales");
    printf("\n\n");

//intorducing a for loop here as so it will iterate through each month until it iterate through 12th month. 
    for (int i = 0; i < 12; i++)

    {//now basically for every specific month, printing the month name and parallel to that prinitning sales for desired output. 
//here the month is 10 character field left aligned and moth is setted to two decimal. 
        printf("%-10s $%.2f\n", monthly[i].month_key, monthly[i].sales_val);

    }

}


// As per the desired outcome, defining function for sales summary which includes the max, min and average of sales. 
void sale_summary()

{//firstly, intializing a variable which will store the max, min and total sale. Then to store the month name along with max and min sale, making an sarray.

    float sale_max = monthly[0].sales_val, sale_min = sale_max, sale_average = 0, sale_total = 0;
    char month_max[100], month_min[100];
    printf("Sales Summary \n\n");

//introducing an for loop which can iterate through every month's sale.
    for (int i = 0; i < 12; i++)

    {//Here I am conditioning to itereate thorugh every single month's sale while updating the max and min sale as well as making sure that the months also gets updated at the same time for new max and min. 
        if (monthly[i].sales_val > sale_max)
        {
            sale_max = monthly[i].sales_val;
            strcpy(month_max, monthly[i].month_key);
        }
        if (monthly[i].sales_val <= sale_min)
        {
            sale_min = monthly[i].sales_val;
            strcpy(month_min, monthly[i].month_key);
        }

//collecting the final sale for average. 
        sale_total += monthly[i].sales_val;

    }
//calculating the average by diving with 12 and then printing max, min, and average. 
    sale_average = sale_total / 12;
    printf("Minimum sales: $%.2f (%s)\n", sale_min, month_min);
    printf("Maximum sales: $%.2f (%s)\n", sale_max, month_max);
    printf("Average sales: $%.2f\n", sale_average);
}

//defining the function for desired output six month average report from sales.
void six_month_report()
{
    char month_max[100], month_min[100];
    float sale_average = 0;
    printf("Six-Month Moving Average Report:\n\n");

//conditioning a for loop to iterate through 1 to 7th month.
    for (int i = 0; i <= 6; i++)

    {
        float sale_total = 0;
        //now intorducing another for loop to accumulate data of sales over a particular period of 6 months. 
        for (int j = i; j <= (5 + i); j++)

        {
            sale_total += monthly[j].sales_val;
        }

        sale_average = sale_total / 6;
        printf("%-10s - %-10s $%.2f\n", monthly[i].month_key, monthly[i + 5].month_key, sale_average);
    }
}

//here as per our desire output, defining function which will sort and print the montly sales from highest to lowest. 
void highest_to_lowest()
{
    float temp_val;
//first loop to iterate through month.
    for (int i = 0; i < 12; i++)
    {//and now this loop which will compare the month's sales with each other. 
        for (int j = 0; j < 12; j++)
        {
            //this piece of code will compare the sales of two month and swap their value and month name. 
            if (monthly[i].sales_val > monthly[j].sales_val)
            {
                temp_val = monthly[i].sales_val;
                monthly[i].sales_val = monthly[j].sales_val;
                monthly[j].sales_val = temp_val;
                struct value_main temp_month;
                strcpy(temp_month.month_key, monthly[i].month_key);
                strcpy(monthly[i].month_key, monthly[j].month_key);
                strcpy(monthly[j].month_key, temp_month.month_key);
            }
        }
    }

    printf("Sales Report (Highest to Lowest):\n\n");
    printf("%-10s %-10s\n", "Month", "Sales");
    printf("\n");

//atlast iterating through sorted array and priting each month's sale. 
    for (int i = 0; i < 12; ++i)
    {
        printf("%-10s: $%-10.2f\n", monthly[i].month_key, monthly[i].sales_val);
    }
}

//this main function is calling functions from above and calculate the result. 
int main()
{
    temp_dict();
    montly_sales_report();
    printf("\n");
    printf("\n");
    sale_summary();
    printf("\n");
    printf("\n");
    six_month_report();
    printf("\n");
    printf("\n");
    highest_to_lowest();
    return 0;
}