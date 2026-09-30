#ifndef AI_H
#define AI_H

#include "Player.h"

enum class AIStrategy {
    RANDOM,
    AGGRESSIVE,
    SMART
};

class AI : public Player {
private:
    AIStrategy strategy;
    
    // Strategie di scelta
    int selectCardRandom(const Card& topCard, CardColor currentColor = CardColor::RED);
    int selectCardAggressive(const Card& topCard, CardColor currentColor = CardColor::RED);
    int selectCardSmart(const Card& topCard, CardColor currentColor = CardColor::RED);
    
    // Utility per strategie
    bool hasWildCard() const;
    bool hasSpecialCard() const;
    CardColor getMostFrequentColor() const;

public:
    AI(const std::string& name, int id, AIStrategy strategy = AIStrategy::RANDOM);
    virtual ~AI();
    
    // Override metodi virtuali
    int chooseCard(const Card& topCard) override;
    int chooseCard(const Card& topCard, CardColor currentColor);
    CardColor chooseWildColor() const override;
    
    // Getters
    AIStrategy getStrategy() const;
};

#endif // AI_H
