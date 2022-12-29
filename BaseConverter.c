#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Pour utiliser la fonction strlen()
#include <math.h>   // Pour utiliser la fonction pow()

// declaration des fonctions
int decimal(int, char[]);
int strTochiffres(int, char);
// variable global
char chiffres[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'}; // en peut utilise switch-case

int main()
{

    /*
    Nombre: Nombre que nous voulons convertir
    Finale: la Valeur Finale
    */
    char Nombre[10], Finale[50];

    int Base1, Base2;        // la base de depart et la base de finale
    long long int converted; // Nombre en Base 10
    // initialisation des valeurs
    printf("Entrer la Base de nombre:\n");
    scanf("%d", &Base1);
    printf("Entrer le nombre:\n");
    scanf("%s", &Nombre);
    printf("Entrer la Base2:\n");
    scanf("%d", &Base2);

    converted = decimal(Base1, Nombre); // appeler la fonction decimal pour converter "Nombre" a la base 10
    int n = 0;
    int quotient; // le quotient de la division
    // si base2 == 10 on affiche la valeur de variable "converted"
    // sinon on fait la division pour convertir le variable "converted" a la base2.
    if (Base2 != 10)
    {
        while (converted != 0)
        {
            quotient = converted % Base2;
            Finale[n] = chiffres[quotient]; // on stocke la valeur de chiffres[quotient] dans le tableau final
            converted /= Base2;
            n++;
        }
        // for boucle pour afficher les valeurs de tableaux Finale à l'envers.
        printf("Le resultat est:\n");
        for (int j = n - 1; j >= 0; j--)
        {
            printf("%c", Finale[j]);
        }
    }
    else
    {
        // afficher la valeur de variable "converted" (en base 10).
        printf("le resultat est: %d", converted);
    }
    return 0;
}
// la fonction qui converter le variable "Nombre" de base1 a la base 10.
int decimal(int Base1, char Nombre[])
{
    int index = 0;
    int decimal = 0;
    // strlen(): le nombre des chiffres de variable "Nombre".
    for (int puissance = strlen(Nombre) - 1; puissance >= 0; puissance--)
    {

        // dec = chiffre1*Base^0 + chiffre2*Base^1 + ...+ dernierchiffre*Base^strlen(Nombre)
        decimal += strTochiffres(Base1, Nombre[index]) * pow(Base1, puissance);
        index++;
    }
    return decimal;
}
// la fonction qui converter les characters de variable "Nombre" a type int.
int strTochiffres(int base1, char chiffre)
{
    for (int c = 0; c < sizeof(chiffres); c++)
    {
        if (chiffre == chiffres[c])
        {
            // vérifier si le chiffre est plus petite que la base1
            // si chiffre > base1 on afficher Erruer et on quitons le programme.
            if (c < base1)
            {
                return c;
            }
            else
            {
                printf("Erreur: chiffre > base");
                exit(EXIT_FAILURE);
            }
        }
    }
    // si le chiffre n'existe pas en variable "chiffres"  en afficher une erreur et en quitons le programe.
    printf("chiffre n'existe pas;");
    exit(EXIT_FAILURE);
};
