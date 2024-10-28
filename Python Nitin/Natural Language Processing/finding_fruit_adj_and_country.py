import spacy 
nlp = spacy.load("en_core_web_sm")
fruit_adjectives = []
fruit_origins = []
doc = nlp(u"Kiwano has jelly like flash with a refreshingly fruity taste. This is a nice exotic fruit from Africa. It is definitely worth trying.")
for i, token in enumerate(doc):
    if token.text == "fruit":
        fruit_adjectives += [adj for adj in token.lefts if adj.pos_ == "ADJ"]
        fruit_origins += [doc[modifier.i + 1].text for modifier in token.rights if modifier.text == "from" and doc[modifier.i + 1].ent_type != 0]
print("Fruit Adjectives: ", fruit_adjectives)
print("Fruit Origins: ", fruit_origins)
