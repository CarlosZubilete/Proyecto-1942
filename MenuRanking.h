#pragma once
#include <SFML/Graphics.hpp>
#include "RankingArchivo.h"
#include "Ranking.h"
#include "Fecha.h"

class MenuRanking : public sf::Drawable
{
public:
    MenuRanking();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void update();

    void setRankingLeido(std::string&);

    std::string getRankingLeido() const;

    void grabarUltimaJugada(int puntos); // TODO: Este constructor debe guardar el nombre tambien cuando este la pantalla de input

    int obtenerRankingMasBajo() const;

    int obtenerRankingMasAlto() const;

private:
    sf::Font font;
    sf::Text texto;
    sf::Text texto_front;
    sf::String lectura_ranking;
    sf::Sprite fondo;
    sf::Texture fondo_texture;

    std::string _rankingleido;
    int _rankingMasBajo;
    int _rankingMasAlto;
    int _cantidadRegistros;


};
