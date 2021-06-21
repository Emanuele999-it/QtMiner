<<<<<<< HEAD
﻿#include "../Header/carta/clonecards.h"
=======
﻿#include "Model\Header\carta\clonecards.h"
>>>>>>> ale

CloneCards::CloneCards(){}

CloneCards* CloneCards::clone() const {
    return new CloneCards(*this);
}

CloneCards::CloneCards(const CloneCards& c){}
