#pragma once

#include <SFML/Graphics.hpp>
#include "RankingArchivo.h"

class MenuRanking : public sf::Drawable
{
public:
    MenuRanking();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void update();

    void setRankingLeido(std::string&);

    std::string getRankingLeido() const;

private:
    sf::Font font;
    sf::Text texto;
    sf::Text texto_front;
    sf::String lectura_ranking;
    sf::Sprite fondo;
    sf::Texture fondo_texture;

    std::string _rankingleido;
    int rankingMasBajo;
    int rankingMasAlto;
    int cantidadRegistros;


};