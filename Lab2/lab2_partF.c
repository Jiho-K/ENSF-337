//name: Jiho Kim


#include <stdio.h>
#include <stdlib.h>

void get_user_input(double* distance,  double* speed);
void travel_time_hours_and_minutes(double distance, double speed, double *hours, double *minutes);
void display_info( double distance, double speed, double hour, double minutes);

int main(void)
{
	double distance, speed, hours, minutes;
	get_user_input(&distance, &speed);
	travel_time_hours_and_minutes(distance, speed, &hours, &minutes);
	display_info(distance, speed, hours, minutes);
	
}

void get_user_input(double* distance,  double* speed)
{
	printf("Please enter the travel distance in km: ");
	scanf("%lf", distance);
	printf("\nNow enter the vehicle's average speed (km/hr): ");
	scanf("%lf", speed);
	
}

void travel_time_hours_and_minutes(double distance, double speed, double *hours, double *minutes)
{
	*hours = (int) (distance/speed);
	*minutes = ((distance/speed) - *hours) * 60;
}

void display_info( double distance, double speed, double hour, double minutes)
{
	printf("\nYou have travel %.2f (km) with a speed of %.2f in %.2f hour(s) and %.2f minute(s)", distance, speed, hour, minutes );
}
