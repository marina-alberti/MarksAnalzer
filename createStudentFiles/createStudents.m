numStudent = 20;
numSubject = 8;
nameSubject = {'italian', 'english', 'math', 'biology', 'physics', ...
    'latin', 'history', 'french'};

% for each student
for iStudent = 1:numStudent
    roll = num2str(iStudent);
    rollDigits = length(roll);
    if rollDigits == 1
        rollOut = ['0', roll];
    else
        rollOut = roll;
    end
    filename = ['student', rollOut];
    f = fopen(filename, 'w'); 
    fprintf(f, [filename, ',', num2str(iStudent), '\n']);
    meanStudent = random('unif', 5, 8);
    % for each of the subjects
    for iSubject = 1: numSubject
        mark = round(meanStudent + random('unif', (-2), 2));
        fprintf(f, [nameSubject{iSubject}, ' ', num2str(mark) , '\n']);  %
    end
    fclose(f);
end
    
    