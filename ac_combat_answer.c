#ifndef GET_ANSWER_SCRIPT
#define GET_ANSWER_SCRIPT
public void get_question_answer(mixed &question, mixed &answer)
{
    question = random() & 0x0FFFFFFF;
    answer = (question * 7 ^ 0x8587833 + 1933) & 0x7FFFFFFF;
}
#endif

#ifndef SERVER_TYPE
#ifndef SET_ANSWER_SCRIPT
#define SET_ANSWER_SCRIPT
int _answer = UNDEFINED;
override public void set_answer_by_question(int question)
{
    if (get_thread_id() == 0)
    {
        create_thread(0, (: set_answer_by_question :), question);
        return;
    }
    _answer = (question * 7 ^ 0x8587833 + 1933) & 0x7FFFFFFF;
}
#endif
#endif
