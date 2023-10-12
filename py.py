def sum_of_intervals(intervals):
    intervals =  sorted(set(intervals))
    for i in range(len(intervals)-1):
        if intervals[i][1] >= intervals[i+1][0]:
            match intervals[i+1][1] >= intervals[i][1]:
                case True: intervals[i+1] = (intervals[i][0], intervals[i+1][1])
                case _: intervals[i+1] = (intervals[i][0], intervals[i][1])
            intervals[i] = set()
    intervals = sum(i[1]-i[0] for i in intervals if i != set())
    return intervals

print(sum_of_intervals([(-10,100)]))