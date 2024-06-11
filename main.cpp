#include "window.hpp"

// pour pouvoir utiliser la librairie graphique, il faut juste créer une window, écrire le fichier UI (user interface) et lancer la loop principale de al fenètre

int main() 
{
    Window::my_Window win; // apport de la classe "my_Window" au nom de "win"
    Window::my_Window::Window_info window_data;

    window_data.title = "ERP : RECE PDF PART v0.0"; // le titre sera "ERP : RECE PDF PART v0.0"
    window_data.height = 1080;  // la hauteur sera de 1080
    window_data.lenght = 1920;  // la largeur seta de 1920
    window_data.FPS = 60;   // le taux d'image par seconde sera de 60
    window_data.bg_color = sf::Color::White;

    win.set_window_data(window_data);   // setter des données de la window dans la classe
    win.window(); // création de la fenètre a partir de la fonction widow se trouvant dans win
    UI(win);    // appel de la fonction de création des données de l'interface graphique
    win.loop(); // boucle principale de la fenètre (evenements, affichage, etc...)
    return 0; // valeur de retour obligatoire du main
}
