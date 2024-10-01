from spacy.tokens.doc import Doc
from spacy.vocab import Vocab

doc = Doc(Vocab(), words = [u"Hi", u"There"])
print(doc)