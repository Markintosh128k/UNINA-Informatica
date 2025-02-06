from pygments.lexer import RegexLexer
from pygments.token import Text, Keyword, Name, String, Number, Operator

class PLikeLexer(RegexLexer):
    name = "PLike"
    aliases = ["plike"]
    filenames = ["*.plike"]

    tokens = {
        'root': [
            (r'\b(begin|end|var|if|then|else|endif|for|to|do|endfor|while|repeat|until|print|read|procedure|function|logical|integer|real|array|character)\b', Keyword),
            (r'\b(TRUE|FALSE)\b', Keyword.Constant),
            (r'\:=', Operator),
            (r'[+\-*/=<>]', Operator),
            (r'[\w_][\w\d_]*', Name),
            (r'\".*?\"', String),
            (r'\d+\.\d+', Number.Float),
            (r'\d+', Number.Integer),
            (r'\(\*.*?\*\)', Text),  # Commenti (* *)
            (r'[\s]+', Text),
        ]
    }

# Scrivi un file setup.py per installare il lexer personalizzato
setup_script = """
from setuptools import setup

setup(
    name='pygments-plike-lexer',
    version='1.0',
    description='Pygments lexer for P-Like language',
    packages=['plike_lexer'],
    entry_points='''
    [pygments.lexers]
    plikelexer=plike_lexer:PLikeLexer
    ''',
)
"""

# Salva il lexer e il setup script in una struttura di directory
lexer_code = '''from pygments.lexer import RegexLexer
from pygments.token import Text, Keyword, Name, String, Number, Operator

class PLikeLexer(RegexLexer):
    name = "PLike"
    aliases = ["plike"]
    filenames = ["*.plike"]

    tokens = {
        'root': [
            (r'\\b(begin|end|var|if|then|else|endif|for|to|do|endfor|while|repeat|until|print|read|procedure|function|logical|integer|real|array|character)\\b', Keyword),
            (r'\\b(TRUE|FALSE)\\b', Keyword.Constant),
            (r'\\:=', Operator),
            (r'[+\\-*/=<>]', Operator),
            (r'[\\w_][\\w\\d_]*', Name),
            (r'\\".*?\\"', String),
            (r'\\d+\\.\\d+', Number.Float),
            (r'\\d+', Number.Integer),
            (r'\\(\\*.*?\\*\\)', Text),  # Commenti (* *)
            (r'[\\s]+', Text),
        ]
    }
'''