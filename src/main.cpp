#include <stdio.h>
// Initialiser la grille
void initialiser(char grille[3][3])
{
    int i, j;
    for (i=0; i<3; i++)
    {
        for (j=0; j<3; j++)
        {
            grille[i][j]=' ';
        }
    }
}
// Afficher la grille
void afficher(char grille[3][3])
{
    int i;
    printf("\n");
    for (i=0; i<3; i++)
    {
        printf(" %c | %c | %c \n",
               grille[i][0],
               grille[i][1],
               grille[i][2]);
        if (i<2)
            printf("---+---+---\n");
    }
    printf("\n");
}

// Jouer un tour
void jouer(char grille[3][3], char joueur)
{
    int l, c;
    do
    {
        printf("Joueur %c\n", joueur);
        printf("Donner la ligne (1-3) : ");
        scanf("%d", &l);
        printf("Donner la colonne (1-3) : ");
        scanf("%d", &c);
        if (l < 1 || l > 3 || c < 1 || c > 3)
        {
            printf("Position invalide !\n");
        }
        else if (grille[l-1][c-1]!= ' ')
        {
            printf("Case deja occupee !\n");
        }
        else
        {
            grille[l-1][c-1] = joueur;
            return;
        }

    } while (1);
}
// Verifier le gagnant
int gagnant(char grille[3][3], char joueur)
{
    int i;
    // Verifier les lignes
    for (i=0; i<3; i++)
    {
        if (grille[i][0]==joueur && grille[i][1]==joueur && grille[i][2]==joueur)
            return 1;
    }
    // Verifier les colonnes
    for (i=0; i<3;i++)
    {
        if (grille[0][i]==joueur &&  grille[1][i]==joueur && grille[2][i]==joueur)
            return 1;
    }
    // Verifier les diagonales
    if (grille[0][0] == joueur && grille[1][1] == joueur && grille[2][2] == joueur)
        return 1;

    if (grille[0][2] == joueur && grille[1][1] == joueur && grille[2][0] == joueur)
        return 1;

    return 0;
}

// Verifier le match nul
int matchNul(char grille[3][3])
{
    int i,j;
    for (i=0; i<3; i++)
    {
        for (j=0; j<3;j++)
        {
            if (grille[i][j]==' ')
                return 0;
        }
    }
    return 1;
}
// Programme principal
int main()
{
    char grille[3][3];
    char joueur;
    int scoreX=0, scoreO=0;
    int rejouer;
    do
    {
        initialiser(grille);
        joueur = 'X';
        printf("\n===== TIC TAC TOE =====\n");
        do
        {
            afficher(grille);
            jouer(grille, joueur);
            if (gagnant(grille, joueur))
            {
                afficher(grille);
                printf("Le joueur %c a gagne !\n", joueur);
                if (joueur == 'X')
                    scoreX++;
                else
                    scoreO++;

                break;
            }
            if (matchNul(grille))
            {
                afficher(grille);
                printf("Match nul !\n");
                break;
            }
            // Changer de joueur
            if (joueur == 'X')
                joueur = 'O';
            else
                joueur = 'X';

        } while (1);

        printf("\n===== SCORES =====\n");
        printf("Joueur X : %d\n", scoreX);
        printf("Joueur O : %d\n", scoreO);

        printf("\nVoulez-vous rejouer ?\n");
        printf("1. Oui\n");
        printf("0. Non\n");
        printf("Votre choix : ");
        scanf("%d", &rejouer);

    } while (rejouer == 1);

    printf("\nMerci d'avoir joue !\n");

    return 0;
}
