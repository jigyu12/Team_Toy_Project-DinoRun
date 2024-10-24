#include "pch.h"
#include "TextGameObject.h"

TextGameObject::TextGameObject(const std::string& fontId, const std::string& textString, const std::string& name, const sf::Color color)
	: GameObject(name), fontId(fontId), textString(textString), color(color)
{
}

void TextGameObject::Init()
{
	text.setFont(FONT_MANAGER.Get(fontId));
	text.setString(textString);
	text.setCharacterSize(100);
	text.setFillColor(color);
	SetOrigin(originPreset);
}

void TextGameObject::Update(float dt)
{
	text.setPosition({ text.getPosition().x + (speed.x * dt), text.getPosition().y + (speed.y * dt) });
}

void TextGameObject::Render(sf::RenderWindow& window)
{
	window.draw(text);
}

void TextGameObject::Release()
{

}

void TextGameObject::SetOrigin(Origins preset)
{
	originPreset = preset;
	origin = Utils::SetOrigin(text, originPreset);
	text.setOrigin(origin);
}

void TextGameObject::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = newOrigin;
	text.setOrigin(origin);
}

void TextGameObject::SetPosition(const sf::Vector2f& pos)
{
	text.setPosition(pos);
	position = text.getPosition();
}

void TextGameObject::SetColor(const sf::Color& newColor)
{
	text.setFillColor(newColor);
	color = newColor;
}

void TextGameObject::SetTextString(const std::string& newTextString)
{
	text.setString(newTextString);
	textString = newTextString;
}