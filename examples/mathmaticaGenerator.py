from wolframclient.evaluation import WolframLanguageSession

from wolframclient.language import wl, wlexpr
session = WolframLanguageSession()
session.evaluate(wl.RandomReal)