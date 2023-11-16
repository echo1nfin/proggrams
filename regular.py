import re

text = '''<B>abc</B> hi <B>zxcv</B>'''
print(re.findall(r'<[Bb]>.*?<\/[Bb]>', text))