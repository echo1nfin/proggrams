def alphabet_war(battlefield):
    if '#' not in battlefield:
        return battlefield.replace('[', '').replace(']','')
    elif '#' in battlefield and '[' not in battlefield:
        return ""

    alph = ''
    battlefield = [''] + battlefield.replace('[', '=*').replace(']', '*=').split('=') + ['']
    for i in range(1, len(battlefield)-1):
        if '#' not in battlefield[i] and '*' in battlefield[i] and (battlefield[i-1].count('#') + battlefield[i+1].count('#')) <= battlefield[i].count('*')/2:
            alph += battlefield[i][1:-1]
    return alph
print(alphabet_war('[a][b][c]'))