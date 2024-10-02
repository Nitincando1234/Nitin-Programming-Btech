import spacy 
from spacy.matcher import Matcher
nlp = spacy.load("en_core_web_sm")
matcher = Matcher(nlp.vocab)
pattern = [{"DEP": "nsubj"}, {"DEP": "aux"}, {"DEP": "ROOT"}]
matcher.add("NewPattern", [pattern])
doc = nlp(u"We can Overtake Them.")
match = matcher(doc)
for match_id, start, end in match:
    span = doc[start: end]
    print(span.text)
