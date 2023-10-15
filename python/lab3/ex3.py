subject_dict = {}

with open('AcademicSubjects.txt', 'r', encoding='utf-8') as file:
    for line in file:
        parts = line.strip().split(':')
        if len(parts) == 2:
            subject = parts[0].strip()
            details = parts[1].strip()

            lesson_parts = details.split()
            total_lessons = 0

            for part in lesson_parts:
                if '(' in part and ')' in part:
                    lesson_count = int(part.split('(')[0])
                    total_lessons += lesson_count

            subject_dict[subject] = total_lessons

print(subject_dict)
