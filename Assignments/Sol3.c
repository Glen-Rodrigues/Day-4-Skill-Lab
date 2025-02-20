#include <stdio.h>
#include <string.h>

struct weather
{
    char city[50];
    int temperature;
    int humidity;
};
typedef struct weather Weather;

void readWeatherData(Weather w[], int n)
{
    printf("Enter details (City, Temperature(°C), Humidity(%)):\n");
    for (int i = 0; i < n; i++)
    {
        printf("City %d: ", i + 1);
        scanf("%s %d %d", w[i].city, &w[i].temperature, &w[i].humidity);
    }
}

void saveWeatherData(Weather w[], int n)
{
    FILE *file = fopen("weather_data.txt", "w");
    if (file == NULL)
    {
        printf("Error in creating file.\n");
        return;
    }
    for (int i = 0; i < n; i++)
        fprintf(file, "%s %d°C %d%%\n", w[i].city, w[i].temperature, w[i].humidity);
    fclose(file);
    printf("Data saved in \"weather_data.txt\"\n");
}

void searchWeather(Weather w[], int n)
{
    char searchCity[50];
    int found = 0;
    printf("Enter city name to search: ");
    scanf("%s", searchCity);
    for (int i = 0; i < n; i++)
    {
        if (strcmp(searchCity, w[i].city) == 0)
        {
            printf("Weather in %s: %d°C, %d%% Humidity\n", w[i].city, w[i].temperature, w[i].humidity);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("City not found in records.\n");
}

int main()
{
    int num_cities;
    Weather records[100];
    printf("Enter number of cities: ");
    scanf("%d", &num_cities);
    readWeatherData(records, num_cities);
    searchWeather(records, num_cities);
    saveWeatherData(records, num_cities);
    return 0;
}
