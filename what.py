# def parse_int(string):
#     nums = {'one': 1,'two': 2,'three': 3,'four': 4,'five': 5,'six': 6,'seven': 7, 'eight': 8, 'nine': 9, 'ten': 10, 'hundred': 100, 'thousand': 1000, 'twenty': 20, 'thirty': 30, 'forty':40, 'fifty': 50, 'sixty': 60, 'seventy': 70, 'eighty': 80, 'ninety': 90, 'eleven': 11, 'twelve': 12, 'thirteen': 13, 'fourteen': 14, 'fifteen': 15, 'sixteen': 16, 'seventeen': 17, 'eighteen': 18, 'nineteen': 19}
#     if 'million' in string:
#         return 1000000
#     if 'zero' in string:
#         return 0
#     string = string.replace(' and','').replace('-',' ')
#     if 'thousand' in string:
#         string = string.split('thousand')
#         if 'hundred' in string[0]:
#             hundred = string[0].split('hundred')
#             count_thousand = (sum(nums.get(i, 0) for i in hundred[0].split())*100 + sum(nums.get(i, 0) for i in hundred[1].split()))*1000
#         else:
#             count_thousand = sum(nums.get(i, 0) for i in string[0].split()) * 1000
#         if 'hundred' in string[1]:
#             hundred_after = string[1].split('hundred')
#             count_hundred = sum(nums.get(i,0) for i in hundred_after[0].split())*100 + sum(nums.get(i,0) for i in hundred_after[1].split())
#         else:
#             count_hundred = sum(nums.get(i,0) for i in string[1].split())
#         return count_thousand + count_hundred
#     else:
#         if 'hundred' in string:
#             hundred = string.split('hundred')
#             count_hundred = sum(nums.get(i,0) for i in hundred[0].split())*100 + sum(nums.get(i,0) for i in hundred[1].split())
#         else:
#             count_hundred = sum(nums.get(i,0) for i in string.split())
#         return count_hundred
# print(parse_int('two hundred and twenty two thousand and two hundred twenty-two'))
# bullshit ^
# nice
words = {w: n for n, w in enumerate('zero one two three four five six seven eight nine ten eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen nineteen'.split())}
words.update({w: 10 * n for n, w in enumerate('twenty thirty forty fifty sixty seventy eighty ninety hundred'.split(), 2)})
thousands = {w: 1000 ** n for n, w in enumerate('thousand million billion trillion quadrillion quintillion sextillion septillion octillion nonillion decillion'.split(), 1)}
def parse_int(strng):
    num = group = 0
    for w in strng.replace(' and ', ' ').replace('-', ' ').split():
        if w == 'hundred': group *= words[w]
        elif w in words: group += words[w]
        else:
            num += group * thousands[w]
            group = 0
    return num + group