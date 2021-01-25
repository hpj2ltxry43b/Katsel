#include "parse/parser.h"
#include "parsestack.h" // in a private header file
#include <vector>
#include <iostream>
#include "utils/format.h"
#include "utils/assert.h"
#include "utils/maybe.h"
#include "message/errmsgs.h"

// get goto {{{
// GETGOTO START
size_t get_goto(NonTerminal nterm, size_t state) {
    switch (nterm) {
        case NonTerminal::_48:
            switch (state) {
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_0:
            switch (state) {
                case 0:
                    return 1;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_49:
            switch (state) {
                case 49:
                    return 63;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_21:
            switch (state) {
                case 19:
                    return 29;
                case 49:
                    return 64;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_51:
            switch (state) {
                case 19:
                    return 28;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_50:
            switch (state) {
                case 19:
                    return 27;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_52:
            switch (state) {
                case 237:
                    return 247;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_20:
            switch (state) {
                case 180: case 183: case 238: case 239: case 241:
                    return 223;
                case 237:
                    return 248;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_54:
            switch (state) {
                case 180: case 183: case 238: case 239: case 241:
                    return 222;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_53:
            switch (state) {
                case 180: case 183: case 238: case 239: case 241:
                    return 221;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_55:
            switch (state) {
                case 190:
                    return 231;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_10:
            switch (state) {
                case 87:
                    return 141;
                case 190:
                    return 232;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_57:
            switch (state) {
                case 87:
                    return 140;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_56:
            switch (state) {
                case 87:
                    return 139;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_58:
            switch (state) {
                case 82:
                    return 137;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_6:
            switch (state) {
                case 76: case 79: case 81: case 136:
                    return 83;
                case 82:
                    return 138;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_59:
            switch (state) {
                case 76: case 79: case 81: case 136:
                    return 82;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_60:
            switch (state) {
                case 2:
                    return 8;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_1:
            switch (state) {
                case 0:
                    return 3;
                case 2:
                    return 9;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_61:
            switch (state) {
                case 0:
                    return 2;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_62:
            switch (state) {
                case 42:
                    return 59;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_5:
            switch (state) {
                case 21: case 41: case 45: case 58:
                    return 43;
                case 42:
                    return 60;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_63:
            switch (state) {
                case 21: case 41: case 45: case 58:
                    return 42;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_64:
            switch (state) {
                case 19:
                    return 26;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_65:
            switch (state) {
                case 180:
                    return 220;
                case 183:
                    return 227;
                case 238:
                    return 249;
                case 239:
                    return 250;
                case 241:
                    return 251;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_66:
            switch (state) {
                case 76:
                    return 80;
                case 79:
                    return 133;
                case 81:
                    return 135;
                case 136:
                    return 188;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_67:
            switch (state) {
                case 21:
                    return 40;
                case 41:
                    return 57;
                case 45:
                    return 61;
                case 58:
                    return 69;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_68:
            switch (state) {
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_24:
            switch (state) {
                case 90:
                    return 148;
                case 96:
                    return 154;
                case 97:
                    return 155;
                case 129:
                    return 185;
                case 180: case 183: case 237: case 238: case 239: case 241:
                    return 224;
                case 233:
                    return 243;
                case 244:
                    return 252;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_69:
            switch (state) {
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_7:
            switch (state) {
                case 76: case 79: case 81: case 82: case 136:
                    return 84;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_70:
            switch (state) {
                case 20:
                    return 36;
                case 71:
                    return 78;
                case 89:
                    return 146;
                case 145:
                    return 193;
                case 147:
                    return 194;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_11:
            switch (state) {
                case 20: case 71: case 89: case 145: case 147:
                    return 37;
                case 62:
                    return 72;
                case 88:
                    return 144;
                case 90:
                    return 149;
                case 139:
                    return 189;
                case 148:
                    return 195;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_71:
            switch (state) {
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_15:
            switch (state) {
                case 32:
                    return 50;
                case 48:
                    return 62;
                case 52:
                    return 66;
                case 142:
                    return 191;
                case 192:
                    return 234;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_2:
            switch (state) {
                case 0: case 2:
                    return 4;
                case 21: case 41: case 42: case 45: case 58:
                    return 44;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_3:
            switch (state) {
                case 0: case 2:
                    return 5;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_12:
            switch (state) {
                case 62:
                    return 71;
                case 154:
                    return 198;
                case 155:
                    return 200;
                case 235:
                    return 245;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_16:
            switch (state) {
                case 7:
                    return 11;
                case 16:
                    return 24;
                case 25:
                    return 47;
                case 51:
                    return 65;
                case 173:
                    return 218;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_4:
            switch (state) {
                case 11:
                    return 20;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_8:
            switch (state) {
                case 76: case 79: case 81: case 82: case 136:
                    return 85;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_9:
            switch (state) {
                case 76: case 79: case 81: case 82: case 136:
                    return 86;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_26:
            switch (state) {
                case 76: case 79: case 81: case 82: case 136:
                    return 88;
                case 90: case 96: case 97: case 129: case 180: case 183: case 233: case 237: case 238: case 239: case 241: case 244:
                    return 151;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_25:
            switch (state) {
                case 76: case 79: case 81: case 82: case 136:
                    return 89;
                case 90: case 96: case 97: case 129: case 180: case 183: case 233: case 237: case 238: case 239: case 241: case 244:
                    return 150;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_13:
            switch (state) {
                case 62: case 154: case 155: case 235:
                    return 73;
                case 76: case 79: case 81: case 82: case 90: case 96: case 97: case 129: case 136: case 180: case 183: case 233: case 237: case 238: case 239: case 241: case 244:
                    return 94;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_14:
            switch (state) {
                case 62: case 154: case 155: case 235:
                    return 74;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_19:
            switch (state) {
                case 7: case 16: case 25: case 51: case 173:
                    return 12;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_17:
            switch (state) {
                case 7: case 16: case 25: case 51: case 173:
                    return 13;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_18:
            switch (state) {
                case 7: case 16: case 25: case 51: case 173:
                    return 14;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_47:
            switch (state) {
                case 7: case 16: case 25: case 51: case 173:
                    return 15;
                case 76: case 79: case 81: case 82: case 90: case 96: case 97: case 109: case 110: case 111: case 112: case 113: case 129: case 136: case 152: case 153: case 156: case 157: case 158: case 159: case 160: case 161: case 162: case 163: case 164: case 165: case 166: case 167: case 168: case 169: case 170: case 171: case 172: case 178: case 180: case 183: case 233: case 237: case 238: case 239: case 241: case 244:
                    return 131;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_23:
            switch (state) {
                case 19: case 49:
                    return 30;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_22:
            switch (state) {
                case 19: case 49:
                    return 31;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_29:
            switch (state) {
                case 76: case 79: case 81: case 82: case 90: case 96: case 97: case 129: case 136: case 180: case 183: case 233: case 237: case 238: case 239: case 241: case 244:
                    return 91;
                case 152:
                    return 196;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_27:
            switch (state) {
                case 76: case 79: case 81: case 82: case 90: case 96: case 97: case 129: case 136: case 180: case 183: case 233: case 237: case 238: case 239: case 241: case 244:
                    return 92;
                case 235:
                    return 246;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_28:
            switch (state) {
                case 76: case 79: case 81: case 82: case 90: case 96: case 97: case 129: case 136: case 180: case 183: case 233: case 237: case 238: case 239: case 241: case 244:
                    return 93;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_30:
            switch (state) {
                case 76: case 79: case 81: case 82: case 90: case 96: case 97: case 129: case 136: case 152: case 180: case 183: case 233: case 237: case 238: case 239: case 241: case 244:
                    return 95;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_31:
            switch (state) {
                case 76: case 79: case 81: case 82: case 90: case 96: case 97: case 129: case 136: case 152: case 180: case 183: case 233: case 237: case 238: case 239: case 241: case 244:
                    return 98;
                case 153:
                    return 197;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_32:
            switch (state) {
                case 76: case 79: case 81: case 82: case 90: case 96: case 97: case 129: case 136: case 152: case 153: case 180: case 183: case 233: case 237: case 238: case 239: case 241: case 244:
                    return 99;
                case 156:
                    return 201;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_33:
            switch (state) {
                case 76: case 79: case 81: case 82: case 90: case 96: case 97: case 129: case 136: case 152: case 153: case 156: case 180: case 183: case 233: case 237: case 238: case 239: case 241: case 244:
                    return 100;
                case 157:
                    return 202;
                case 158:
                    return 203;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_34:
            switch (state) {
                case 76: case 79: case 81: case 82: case 90: case 96: case 97: case 129: case 136: case 152: case 153: case 156: case 157: case 158: case 180: case 183: case 233: case 237: case 238: case 239: case 241: case 244:
                    return 101;
                case 159:
                    return 204;
                case 160:
                    return 205;
                case 161:
                    return 206;
                case 162:
                    return 207;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_35:
            switch (state) {
                case 76: case 79: case 81: case 82: case 90: case 96: case 97: case 129: case 136: case 152: case 153: case 156: case 157: case 158: case 159: case 160: case 161: case 162: case 180: case 183: case 233: case 237: case 238: case 239: case 241: case 244:
                    return 102;
                case 163:
                    return 208;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_36:
            switch (state) {
                case 76: case 79: case 81: case 82: case 90: case 96: case 97: case 129: case 136: case 152: case 153: case 156: case 157: case 158: case 159: case 160: case 161: case 162: case 163: case 180: case 183: case 233: case 237: case 238: case 239: case 241: case 244:
                    return 103;
                case 164:
                    return 209;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_37:
            switch (state) {
                case 76: case 79: case 81: case 82: case 90: case 96: case 97: case 129: case 136: case 152: case 153: case 156: case 157: case 158: case 159: case 160: case 161: case 162: case 163: case 164: case 180: case 183: case 233: case 237: case 238: case 239: case 241: case 244:
                    return 104;
                case 165:
                    return 210;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_38:
            switch (state) {
                case 76: case 79: case 81: case 82: case 90: case 96: case 97: case 129: case 136: case 152: case 153: case 156: case 157: case 158: case 159: case 160: case 161: case 162: case 163: case 164: case 165: case 180: case 183: case 233: case 237: case 238: case 239: case 241: case 244:
                    return 105;
                case 166:
                    return 211;
                case 167:
                    return 212;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_39:
            switch (state) {
                case 76: case 79: case 81: case 82: case 90: case 96: case 97: case 129: case 136: case 152: case 153: case 156: case 157: case 158: case 159: case 160: case 161: case 162: case 163: case 164: case 165: case 166: case 167: case 180: case 183: case 233: case 237: case 238: case 239: case 241: case 244:
                    return 106;
                case 168:
                    return 213;
                case 169:
                    return 214;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_41:
            switch (state) {
                case 76: case 79: case 81: case 82: case 90: case 96: case 97: case 129: case 136: case 152: case 153: case 156: case 157: case 158: case 159: case 160: case 161: case 162: case 163: case 164: case 165: case 166: case 167: case 168: case 169: case 180: case 183: case 233: case 237: case 238: case 239: case 241: case 244:
                    return 108;
                case 109:
                    return 174;
                case 110:
                    return 175;
                case 111:
                    return 176;
                case 112:
                    return 177;
                case 113:
                    return 179;
                case 170:
                    return 215;
                case 171:
                    return 216;
                case 172:
                    return 217;
                case 178:
                    return 219;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_40:
            switch (state) {
                case 76: case 79: case 81: case 82: case 90: case 96: case 97: case 129: case 136: case 152: case 153: case 156: case 157: case 158: case 159: case 160: case 161: case 162: case 163: case 164: case 165: case 166: case 167: case 168: case 169: case 180: case 183: case 233: case 237: case 238: case 239: case 241: case 244:
                    return 107;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_42:
            switch (state) {
                case 76: case 79: case 81: case 82: case 90: case 96: case 97: case 109: case 110: case 111: case 112: case 113: case 129: case 136: case 152: case 153: case 156: case 157: case 158: case 159: case 160: case 161: case 162: case 163: case 164: case 165: case 166: case 167: case 168: case 169: case 170: case 171: case 172: case 178: case 180: case 183: case 233: case 237: case 238: case 239: case 241: case 244:
                    return 114;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_43:
            switch (state) {
                case 76: case 79: case 81: case 82: case 90: case 96: case 97: case 109: case 110: case 111: case 112: case 113: case 129: case 136: case 152: case 153: case 156: case 157: case 158: case 159: case 160: case 161: case 162: case 163: case 164: case 165: case 166: case 167: case 168: case 169: case 170: case 171: case 172: case 178: case 180: case 183: case 233: case 237: case 238: case 239: case 241: case 244:
                    return 115;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_44:
            switch (state) {
                case 76: case 79: case 81: case 82: case 90: case 96: case 97: case 109: case 110: case 111: case 112: case 113: case 129: case 136: case 152: case 153: case 156: case 157: case 158: case 159: case 160: case 161: case 162: case 163: case 164: case 165: case 166: case 167: case 168: case 169: case 170: case 171: case 172: case 178: case 180: case 183: case 233: case 237: case 238: case 239: case 241: case 244:
                    return 116;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_45:
            switch (state) {
                case 76: case 79: case 81: case 82: case 90: case 96: case 97: case 109: case 110: case 111: case 112: case 113: case 129: case 136: case 152: case 153: case 156: case 157: case 158: case 159: case 160: case 161: case 162: case 163: case 164: case 165: case 166: case 167: case 168: case 169: case 170: case 171: case 172: case 178: case 180: case 183: case 233: case 237: case 238: case 239: case 241: case 244:
                    return 117;
                default: report_abort_noh("get invalid goto");
            }
        case NonTerminal::_46:
            switch (state) {
                case 76: case 79: case 81: case 82: case 90: case 96: case 97: case 109: case 110: case 111: case 112: case 113: case 129: case 136: case 152: case 153: case 156: case 157: case 158: case 159: case 160: case 161: case 162: case 163: case 164: case 165: case 166: case 167: case 168: case 169: case 170: case 171: case 172: case 178: case 180: case 183: case 233: case 237: case 238: case 239: case 241: case 244:
                    return 130;
                default: report_abort_noh("get invalid goto");
            }
    }
}
// GETGOTO END
// }}}

static void shift(Parser &p, Token &last, Token &lookahead, std::vector<stackitem> &stack, int &steps, int const &newst) {
    last = lookahead;
    stack.emplace_back(newst, last);
    lookahead = p.consume();
    ++steps;
}

static Token pop_t(std::vector<stackitem> &stack) {
    stackitem si = std::move(stack.back());

    stack.pop_back();
    return std::get<tokenitem>(si.item).tok;
}

template <typename A>
static std::unique_ptr<A> pop_a(std::vector<stackitem> &stack) {
    stackitem si = std::move(stack.back());
    stack.pop_back();

    astitem &as_astitem = std::get<astitem>(si.item);
    std::unique_ptr<A> converted = std::unique_ptr<A>(static_cast<A*>(as_astitem.ast.release()));

    return converted;
}

static void error(bool &done, bool &errored, errorstate const &ers, std::vector<std::string> const &expectations) {
    errored = true;

    if (!error_recovery(ers, expectations))
        done = true;
}

bool _parse(Parser &p, std::vector<stackitem> &stack, bool istrial, std::unique_ptr<ASTNS::CUB> &out, Token const &_lookahead) {
    // PARSERLOOP START {{{
    bool done = false;
    bool errored = false;
    int steps = 0;
    Token lookahead (_lookahead); // for when you need to inject a new token
    Token lasttok = lookahead;
    while (!done) {
        if (istrial && steps > 5)
            return true;
        switch (stack.back().state) {
            case 0:
                switch (lookahead.type) {
                    default: {
                            std::unique_ptr<ASTNS::CU> pushitem = nullptr;
                            stack.emplace_back(get_goto(NonTerminal::_0, stack.back().state), std::move(pushitem), NonTerminal::_0);
                        }
                        break;
                    case TokenType::FUN:
                        shift(p, lasttok, lookahead, stack, steps, 6); break;
                    case TokenType::IMPL:
                        shift(p, lasttok, lookahead, stack, steps, 7); break;
                }
                break;
            case 1:
                switch (lookahead.type) {
                    case TokenType::EOF_:
                            done = true;
                        break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} to terminate {}", stringify_token_type(TokenType::EOF_), "augment")  });
                }
                break;
            case 2:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::DeclList>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
std::unique_ptr<ASTNS::CU> push (std::make_unique<ASTNS::CU>(p.sourcefile, start, end, std::move(a0->decls)));
                            std::unique_ptr<ASTNS::CU> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_0, stack.back().state), std::move(pushitem), NonTerminal::_0);
                        }
                        break;
                    case TokenType::FUN:
                        shift(p, lasttok, lookahead, stack, steps, 6); break;
                    case TokenType::IMPL:
                        shift(p, lasttok, lookahead, stack, steps, 7); break;
                }
                break;
            case 3:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::Decl>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
std::unique_ptr<ASTNS::DeclList> push(std::make_unique<ASTNS::DeclList>(p.sourcefile, start, end, std::vector<std::unique_ptr<ASTNS::Decl>> {}));

        push->decls.push_back(std::move(a0));
                            std::unique_ptr<ASTNS::DeclList> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_61, stack.back().state), std::move(pushitem), NonTerminal::_61);
                        }
                        break;
                }
                break;
            case 4:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::FunctionDecl>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::Decl> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_1, stack.back().state), std::move(pushitem), NonTerminal::_1);
                        }
                        break;
                }
                break;
            case 5:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::Decl>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::Decl> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_1, stack.back().state), std::move(pushitem), NonTerminal::_1);
                        }
                        break;
                }
                break;
            case 6:
                switch (lookahead.type) {
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 10); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", stringify_token_type(TokenType::IDENTIFIER), "function declaration")  });
                }
                break;
            case 7:
                switch (lookahead.type) {
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 16); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 17); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "type specifier", "implementation")  });
                }
                break;
            case 8:
                switch (lookahead.type) {
                    default: {
                            auto a1 (pop_a<ASTNS::Decl>(stack));
                            auto a0 (pop_a<ASTNS::DeclList>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) :
                                a1 ? Maybe(a1->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a1 ? Maybe(a1->end()) :
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
a0->decls.push_back(std::move(a1));
                            std::unique_ptr<ASTNS::DeclList> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_61, stack.back().state), std::move(pushitem), NonTerminal::_61);
                        }
                        break;
                }
                break;
            case 9:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::Decl>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::Decl> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_60, stack.back().state), std::move(pushitem), NonTerminal::_60);
                        }
                        break;
                }
                break;
            case 10:
                switch (lookahead.type) {
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 19); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", stringify_token_type(TokenType::OPARN), "function declaration")  });
                }
                break;
            case 11:
                switch (lookahead.type) {
                    case TokenType::NEWLINE:
                        shift(p, lasttok, lookahead, stack, steps, 22); break;
                    case TokenType::OCURB:
                        shift(p, lasttok, lookahead, stack, steps, 21); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "implementation body", "implementation")  });
                }
                break;
            case 12:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::PathType>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::Type> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_16, stack.back().state), std::move(pushitem), NonTerminal::_16);
                        }
                        break;
                }
                break;
            case 13:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::PointerType>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::Type> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_16, stack.back().state), std::move(pushitem), NonTerminal::_16);
                        }
                        break;
                }
                break;
            case 14:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::ThisType>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::Type> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_16, stack.back().state), std::move(pushitem), NonTerminal::_16);
                        }
                        break;
                }
                break;
            case 15:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::Path>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
std::unique_ptr<ASTNS::PathType> push (std::make_unique<ASTNS::PathType>(p.sourcefile, start, end, std::move(a0)));
                            std::unique_ptr<ASTNS::PathType> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_19, stack.back().state), std::move(pushitem), NonTerminal::_19);
                        }
                        break;
                    case TokenType::DOUBLECOLON:
                        shift(p, lasttok, lookahead, stack, steps, 23); break;
                }
                break;
            case 16:
                switch (lookahead.type) {
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::MUT:
                        shift(p, lasttok, lookahead, stack, steps, 25); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 16); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 17); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", format("either {} or {}", "type specifier", stringify_token_type(TokenType::MUT)), "pointer type")  });
                }
                break;
            case 17:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                Maybe<Location const>(a0);
std::unique_ptr<ASTNS::ThisType> push (std::make_unique<ASTNS::ThisType>(p.sourcefile, start, end, a0));
                            std::unique_ptr<ASTNS::ThisType> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_18, stack.back().state), std::move(pushitem), NonTerminal::_18);
                        }
                        break;
                }
                break;
            case 18:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                Maybe<Location const>(a0);
std::unique_ptr<ASTNS::Path> push(std::make_unique<ASTNS::Path>(p.sourcefile, start, end, std::vector<Token> {}));

        push->segments.push_back(a0);
                            std::unique_ptr<ASTNS::Path> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_47, stack.back().state), std::move(pushitem), NonTerminal::_47);
                        }
                        break;
                }
                break;
            case 19:
                switch (lookahead.type) {
                    case TokenType::CPARN:
{
std::unique_ptr<ASTNS::ParamList> push (std::make_unique<ASTNS::ParamList>(p.sourcefile, Maybe<Location const>(), Maybe<Location const>(), std::vector<std::unique_ptr<ASTNS::ParamB>> {}));
                            std::unique_ptr<ASTNS::ParamList> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_64, stack.back().state), std::move(pushitem), NonTerminal::_64);
                        }
                        break;
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 32); break;
                    case TokenType::MUT:
                        shift(p, lasttok, lookahead, stack, steps, 33); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 35); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 34); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "optional function parameter list", "function declaration")  });
                }
                break;
            case 20:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                    case TokenType::BANG:
                    case TokenType::BININTLIT:
                    case TokenType::CCURB:
                    case TokenType::CHARLIT:
                    case TokenType::DECINTLIT:
                    case TokenType::DEDENT:
                    case TokenType::EOF_:
                    case TokenType::FALSELIT:
                    case TokenType::FLOATLIT:
                    case TokenType::FUN:
                    case TokenType::HEXINTLIT:
                    case TokenType::IDENTIFIER:
                    case TokenType::IF:
                    case TokenType::IMPL:
                    case TokenType::MINUS:
                    case TokenType::NULLPTRLIT:
                    case TokenType::OCTINTLIT:
                    case TokenType::OCURB:
                    case TokenType::OPARN:
                    case TokenType::RETURN:
                    case TokenType::STAR:
                    case TokenType::STRINGLIT:
                    case TokenType::THIS:
                    case TokenType::TILDE:
                    case TokenType::TRUELIT:
                    case TokenType::VAR:
                    case TokenType::WHILE:
{
                            std::unique_ptr<ASTNS::PureLocation> pushitem = nullptr;
                            stack.emplace_back(get_goto(NonTerminal::_70, stack.back().state), std::move(pushitem), NonTerminal::_70);
                        }
                        break;
                    case TokenType::NEWLINE:
                        shift(p, lasttok, lookahead, stack, steps, 38); break;
                    case TokenType::SEMICOLON:
                        shift(p, lasttok, lookahead, stack, steps, 39); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "optional line ending", "implementation")  });
                }
                break;
            case 21:
                switch (lookahead.type) {
                    case TokenType::CCURB:
                    case TokenType::DEDENT:
{
std::unique_ptr<ASTNS::ImplMemberList> push (std::make_unique<ASTNS::ImplMemberList>(p.sourcefile, Maybe<Location const>(), Maybe<Location const>(), std::vector<std::unique_ptr<ASTNS::ImplMember>> {}));
                            std::unique_ptr<ASTNS::ImplMemberList> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_67, stack.back().state), std::move(pushitem), NonTerminal::_67);
                        }
                        break;
                    case TokenType::FUN:
                        shift(p, lasttok, lookahead, stack, steps, 6); break;
                    case TokenType::NEWLINE:
                        shift(p, lasttok, lookahead, stack, steps, 41); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", format("either {} or {}", "optional implementation member list", stringify_token_type(TokenType::NEWLINE)), "implementation body")  });
                }
                break;
            case 22:
                switch (lookahead.type) {
                    case TokenType::INDENT:
                        shift(p, lasttok, lookahead, stack, steps, 45); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", stringify_token_type(TokenType::INDENT), "implementation body")  });
                }
                break;
            case 23:
                switch (lookahead.type) {
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 46); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", stringify_token_type(TokenType::IDENTIFIER), "symbol path")  });
                }
                break;
            case 24:
                switch (lookahead.type) {
                    default: {
                            auto a1 (pop_a<ASTNS::Type>(stack));
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                a1 ? Maybe(a1->end()) :
                                Maybe<Location const>(a0);
std::unique_ptr<ASTNS::PointerType> push (std::make_unique<ASTNS::PointerType>(p.sourcefile, start, end, false, std::move(a1)));
                            std::unique_ptr<ASTNS::PointerType> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_17, stack.back().state), std::move(pushitem), NonTerminal::_17);
                        }
                        break;
                }
                break;
            case 25:
                switch (lookahead.type) {
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 16); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 17); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "type specifier", "pointer type")  });
                }
                break;
            case 26:
                switch (lookahead.type) {
                    case TokenType::CPARN:
                        shift(p, lasttok, lookahead, stack, steps, 48); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", stringify_token_type(TokenType::CPARN), "function declaration")  });
                }
                break;
            case 27:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::ParamList>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::ParamList> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_64, stack.back().state), std::move(pushitem), NonTerminal::_64);
                        }
                        break;
                }
                break;
            case 28:
                switch (lookahead.type) {
                    case TokenType::COMMA:
                        shift(p, lasttok, lookahead, stack, steps, 49); break;
                    default: {
                            auto a0 (pop_a<ASTNS::ParamList>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::ParamList> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_50, stack.back().state), std::move(pushitem), NonTerminal::_50);
                        }
                        break;
                }
                break;
            case 29:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::ParamB>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
std::unique_ptr<ASTNS::ParamList> push(std::make_unique<ASTNS::ParamList>(p.sourcefile, start, end, std::vector<std::unique_ptr<ASTNS::ParamB>> {}));

        push->params.push_back(std::move(a0));
                            std::unique_ptr<ASTNS::ParamList> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_51, stack.back().state), std::move(pushitem), NonTerminal::_51);
                        }
                        break;
                }
                break;
            case 30:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::Param>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::ParamB> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_21, stack.back().state), std::move(pushitem), NonTerminal::_21);
                        }
                        break;
                }
                break;
            case 31:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::ThisParam>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::ParamB> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_21, stack.back().state), std::move(pushitem), NonTerminal::_21);
                        }
                        break;
                }
                break;
            case 32:
                switch (lookahead.type) {
                    case TokenType::COLON:
                        shift(p, lasttok, lookahead, stack, steps, 51); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "required type annotation", "function parameter")  });
                }
                break;
            case 33:
                switch (lookahead.type) {
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 52); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", stringify_token_type(TokenType::IDENTIFIER), "function parameter")  });
                }
                break;
            case 34:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                Maybe<Location const>(a0);
std::unique_ptr<ASTNS::ThisParam> push (std::make_unique<ASTNS::ThisParam>(p.sourcefile, start, end, false, false));
                            std::unique_ptr<ASTNS::ThisParam> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_22, stack.back().state), std::move(pushitem), NonTerminal::_22);
                        }
                        break;
                }
                break;
            case 35:
                switch (lookahead.type) {
                    case TokenType::MUT:
                        shift(p, lasttok, lookahead, stack, steps, 54); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 53); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", format("either {} or {}", stringify_token_type(TokenType::THIS), stringify_token_type(TokenType::MUT)), "'this' function parameter")  });
                }
                break;
            case 36:
                switch (lookahead.type) {
                    default: {
                            auto a3 (pop_a<ASTNS::PureLocation>(stack));
                            auto a2 (pop_a<ASTNS::ImplMemberList>(stack));
                            auto a1 (pop_a<ASTNS::Type>(stack));
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                a1 ? Maybe(a1->end()) :
                                Maybe<Location const>(a0);
std::unique_ptr<ASTNS::ImplDecl> push (std::make_unique<ASTNS::ImplDecl>(p.sourcefile, start, end, std::move(a1), std::move(a2->members)));
                            std::unique_ptr<ASTNS::Decl> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_3, stack.back().state), std::move(pushitem), NonTerminal::_3);
                        }
                        break;
                }
                break;
            case 37:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::PureLocation>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::PureLocation> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_70, stack.back().state), std::move(pushitem), NonTerminal::_70);
                        }
                        break;
                }
                break;
            case 38:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                Maybe<Location const>(a0);
std::unique_ptr<ASTNS::PureLocation> push (std::make_unique<ASTNS::PureLocation>(p.sourcefile, start, end, 0));
                            std::unique_ptr<ASTNS::PureLocation> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_11, stack.back().state), std::move(pushitem), NonTerminal::_11);
                        }
                        break;
                }
                break;
            case 39:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                Maybe<Location const>(a0);
std::unique_ptr<ASTNS::PureLocation> push (std::make_unique<ASTNS::PureLocation>(p.sourcefile, start, end, 0));
                            std::unique_ptr<ASTNS::PureLocation> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_11, stack.back().state), std::move(pushitem), NonTerminal::_11);
                        }
                        break;
                    case TokenType::NEWLINE:
                        shift(p, lasttok, lookahead, stack, steps, 55); break;
                }
                break;
            case 40:
                switch (lookahead.type) {
                    case TokenType::CCURB:
                        shift(p, lasttok, lookahead, stack, steps, 56); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", stringify_token_type(TokenType::CCURB), "implementation body")  });
                }
                break;
            case 41:
                switch (lookahead.type) {
                    case TokenType::CCURB:
                    case TokenType::DEDENT:
{
std::unique_ptr<ASTNS::ImplMemberList> push (std::make_unique<ASTNS::ImplMemberList>(p.sourcefile, Maybe<Location const>(), Maybe<Location const>(), std::vector<std::unique_ptr<ASTNS::ImplMember>> {}));
                            std::unique_ptr<ASTNS::ImplMemberList> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_67, stack.back().state), std::move(pushitem), NonTerminal::_67);
                        }
                        break;
                    case TokenType::FUN:
                        shift(p, lasttok, lookahead, stack, steps, 6); break;
                    case TokenType::INDENT:
                        shift(p, lasttok, lookahead, stack, steps, 58); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", format("either {} or {}", "optional implementation member list", stringify_token_type(TokenType::INDENT)), "implementation body")  });
                }
                break;
            case 42:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::ImplMemberList>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::ImplMemberList> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_67, stack.back().state), std::move(pushitem), NonTerminal::_67);
                        }
                        break;
                    case TokenType::FUN:
                        shift(p, lasttok, lookahead, stack, steps, 6); break;
                }
                break;
            case 43:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::ImplMember>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
std::unique_ptr<ASTNS::ImplMemberList> push(std::make_unique<ASTNS::ImplMemberList>(p.sourcefile, start, end, std::vector<std::unique_ptr<ASTNS::ImplMember>> {}));

        push->members.push_back(std::move(a0));
                            std::unique_ptr<ASTNS::ImplMemberList> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_63, stack.back().state), std::move(pushitem), NonTerminal::_63);
                        }
                        break;
                }
                break;
            case 44:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::FunctionDecl>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
std::unique_ptr<ASTNS::FunctionImplMember> push (std::make_unique<ASTNS::FunctionImplMember>(p.sourcefile, start, end, std::move(a0)));
                            std::unique_ptr<ASTNS::ImplMember> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_5, stack.back().state), std::move(pushitem), NonTerminal::_5);
                        }
                        break;
                }
                break;
            case 45:
                switch (lookahead.type) {
                    case TokenType::CCURB:
                    case TokenType::DEDENT:
{
std::unique_ptr<ASTNS::ImplMemberList> push (std::make_unique<ASTNS::ImplMemberList>(p.sourcefile, Maybe<Location const>(), Maybe<Location const>(), std::vector<std::unique_ptr<ASTNS::ImplMember>> {}));
                            std::unique_ptr<ASTNS::ImplMemberList> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_67, stack.back().state), std::move(pushitem), NonTerminal::_67);
                        }
                        break;
                    case TokenType::FUN:
                        shift(p, lasttok, lookahead, stack, steps, 6); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "optional implementation member list", "implementation body")  });
                }
                break;
            case 46:
                switch (lookahead.type) {
                    default: {
                            auto a2 (pop_t(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_a<ASTNS::Path>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) :
                                Maybe<Location const>(a1);
                            Maybe<Location const> end =
                                Maybe<Location const>(a2);
a0->segments.push_back(a2);
                            std::unique_ptr<ASTNS::Path> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_47, stack.back().state), std::move(pushitem), NonTerminal::_47);
                        }
                        break;
                }
                break;
            case 47:
                switch (lookahead.type) {
                    default: {
                            auto a2 (pop_a<ASTNS::Type>(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                a2 ? Maybe(a2->end()) :
                                Maybe<Location const>(a1);
std::unique_ptr<ASTNS::PointerType> push (std::make_unique<ASTNS::PointerType>(p.sourcefile, start, end, true, std::move(a2)));
                            std::unique_ptr<ASTNS::PointerType> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_17, stack.back().state), std::move(pushitem), NonTerminal::_17);
                        }
                        break;
                }
                break;
            case 48:
                switch (lookahead.type) {
                    case TokenType::COLON:
                        shift(p, lasttok, lookahead, stack, steps, 51); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "required type annotation", "function declaration")  });
                }
                break;
            case 49:
                switch (lookahead.type) {
                    default: {
                            auto a1 (pop_t(stack));
                            auto a0 (pop_a<ASTNS::ParamList>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) :
                                Maybe<Location const>(a1);
                            Maybe<Location const> end =
                                Maybe<Location const>(a1);
                            std::unique_ptr<ASTNS::ParamList> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_50, stack.back().state), std::move(pushitem), NonTerminal::_50);
                        }
                        break;
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 32); break;
                    case TokenType::MUT:
                        shift(p, lasttok, lookahead, stack, steps, 33); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 35); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 34); break;
                }
                break;
            case 50:
                switch (lookahead.type) {
                    default: {
                            auto a1 (pop_a<ASTNS::Type>(stack));
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                a1 ? Maybe(a1->end()) :
                                Maybe<Location const>(a0);
std::unique_ptr<ASTNS::Param> push (std::make_unique<ASTNS::Param>(p.sourcefile, start, end, std::move(a1), a0, false));
                            std::unique_ptr<ASTNS::Param> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_23, stack.back().state), std::move(pushitem), NonTerminal::_23);
                        }
                        break;
                }
                break;
            case 51:
                switch (lookahead.type) {
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 16); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 17); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "type specifier", "required type annotation")  });
                }
                break;
            case 52:
                switch (lookahead.type) {
                    case TokenType::COLON:
                        shift(p, lasttok, lookahead, stack, steps, 51); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "required type annotation", "function parameter")  });
                }
                break;
            case 53:
                switch (lookahead.type) {
                    default: {
                            auto a1 (pop_t(stack));
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                Maybe<Location const>(a1);
std::unique_ptr<ASTNS::ThisParam> push (std::make_unique<ASTNS::ThisParam>(p.sourcefile, start, end, true, false));
                            std::unique_ptr<ASTNS::ThisParam> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_22, stack.back().state), std::move(pushitem), NonTerminal::_22);
                        }
                        break;
                }
                break;
            case 54:
                switch (lookahead.type) {
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 67); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", stringify_token_type(TokenType::THIS), "'this' function parameter")  });
                }
                break;
            case 55:
                switch (lookahead.type) {
                    default: {
                            auto a1 (pop_t(stack));
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                Maybe<Location const>(a1);
WARN_EXTRA_SEMI(a0);std::unique_ptr<ASTNS::PureLocation> push (std::make_unique<ASTNS::PureLocation>(p.sourcefile, start, end, 0));
                            std::unique_ptr<ASTNS::PureLocation> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_11, stack.back().state), std::move(pushitem), NonTerminal::_11);
                        }
                        break;
                }
                break;
            case 56:
                switch (lookahead.type) {
                    default: {
                            auto a2 (pop_t(stack));
                            auto a1 (pop_a<ASTNS::ImplMemberList>(stack));
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                Maybe<Location const>(a2);
                            std::unique_ptr<ASTNS::ImplMemberList> pushitem = std::move(a1);
                            stack.emplace_back(get_goto(NonTerminal::_4, stack.back().state), std::move(pushitem), NonTerminal::_4);
                        }
                        break;
                }
                break;
            case 57:
                switch (lookahead.type) {
                    case TokenType::CCURB:
                        shift(p, lasttok, lookahead, stack, steps, 68); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", stringify_token_type(TokenType::CCURB), "implementation body")  });
                }
                break;
            case 58:
                switch (lookahead.type) {
                    case TokenType::CCURB:
                    case TokenType::DEDENT:
{
std::unique_ptr<ASTNS::ImplMemberList> push (std::make_unique<ASTNS::ImplMemberList>(p.sourcefile, Maybe<Location const>(), Maybe<Location const>(), std::vector<std::unique_ptr<ASTNS::ImplMember>> {}));
                            std::unique_ptr<ASTNS::ImplMemberList> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_67, stack.back().state), std::move(pushitem), NonTerminal::_67);
                        }
                        break;
                    case TokenType::FUN:
                        shift(p, lasttok, lookahead, stack, steps, 6); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "optional implementation member list", "implementation body")  });
                }
                break;
            case 59:
                switch (lookahead.type) {
                    default: {
                            auto a1 (pop_a<ASTNS::ImplMember>(stack));
                            auto a0 (pop_a<ASTNS::ImplMemberList>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) :
                                a1 ? Maybe(a1->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a1 ? Maybe(a1->end()) :
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
a0->members.push_back(std::move(a1));
                            std::unique_ptr<ASTNS::ImplMemberList> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_63, stack.back().state), std::move(pushitem), NonTerminal::_63);
                        }
                        break;
                }
                break;
            case 60:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::ImplMember>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::ImplMember> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_62, stack.back().state), std::move(pushitem), NonTerminal::_62);
                        }
                        break;
                }
                break;
            case 61:
                switch (lookahead.type) {
                    case TokenType::DEDENT:
                        shift(p, lasttok, lookahead, stack, steps, 70); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", stringify_token_type(TokenType::DEDENT), "implementation body")  });
                }
                break;
            case 62:
                switch (lookahead.type) {
                    case TokenType::NEWLINE:
                        shift(p, lasttok, lookahead, stack, steps, 75); break;
                    case TokenType::OCURB:
                        shift(p, lasttok, lookahead, stack, steps, 76); break;
                    case TokenType::SEMICOLON:
                        shift(p, lasttok, lookahead, stack, steps, 39); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", format("either {} or {}", "code block", "line ending"), "function declaration")  });
                }
                break;
            case 63:
                switch (lookahead.type) {
                    default: {
                            auto a2 (pop_a<ASTNS::ParamB>(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_a<ASTNS::ParamList>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) :
                                Maybe<Location const>(a1);
                            Maybe<Location const> end =
                                a2 ? Maybe(a2->end()) :
                                Maybe<Location const>(a1);
a0->params.push_back(std::move(a2));
                            std::unique_ptr<ASTNS::ParamList> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_51, stack.back().state), std::move(pushitem), NonTerminal::_51);
                        }
                        break;
                }
                break;
            case 64:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::ParamB>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::ParamB> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_49, stack.back().state), std::move(pushitem), NonTerminal::_49);
                        }
                        break;
                }
                break;
            case 65:
                switch (lookahead.type) {
                    default: {
                            auto a1 (pop_a<ASTNS::Type>(stack));
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                a1 ? Maybe(a1->end()) :
                                Maybe<Location const>(a0);
                            std::unique_ptr<ASTNS::Type> pushitem = std::move(a1);
                            stack.emplace_back(get_goto(NonTerminal::_15, stack.back().state), std::move(pushitem), NonTerminal::_15);
                        }
                        break;
                }
                break;
            case 66:
                switch (lookahead.type) {
                    default: {
                            auto a2 (pop_a<ASTNS::Type>(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                a2 ? Maybe(a2->end()) :
                                Maybe<Location const>(a1);
std::unique_ptr<ASTNS::Param> push (std::make_unique<ASTNS::Param>(p.sourcefile, start, end, std::move(a2), a1, true));
                            std::unique_ptr<ASTNS::Param> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_23, stack.back().state), std::move(pushitem), NonTerminal::_23);
                        }
                        break;
                }
                break;
            case 67:
                switch (lookahead.type) {
                    default: {
                            auto a2 (pop_t(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                Maybe<Location const>(a2);
std::unique_ptr<ASTNS::ThisParam> push (std::make_unique<ASTNS::ThisParam>(p.sourcefile, start, end, true, true));
                            std::unique_ptr<ASTNS::ThisParam> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_22, stack.back().state), std::move(pushitem), NonTerminal::_22);
                        }
                        break;
                }
                break;
            case 68:
                switch (lookahead.type) {
                    default: {
                            auto a3 (pop_t(stack));
                            auto a2 (pop_a<ASTNS::ImplMemberList>(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                Maybe<Location const>(a3);
WARN_BLOCK_NO_INDENT(a0, a3);                            std::unique_ptr<ASTNS::ImplMemberList> pushitem = std::move(a2);
                            stack.emplace_back(get_goto(NonTerminal::_4, stack.back().state), std::move(pushitem), NonTerminal::_4);
                        }
                        break;
                }
                break;
            case 69:
                switch (lookahead.type) {
                    case TokenType::DEDENT:
                        shift(p, lasttok, lookahead, stack, steps, 77); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", stringify_token_type(TokenType::DEDENT), "implementation body")  });
                }
                break;
            case 70:
                switch (lookahead.type) {
                    default: {
                            auto a3 (pop_t(stack));
                            auto a2 (pop_a<ASTNS::ImplMemberList>(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                Maybe<Location const>(a3);
                            std::unique_ptr<ASTNS::ImplMemberList> pushitem = std::move(a2);
                            stack.emplace_back(get_goto(NonTerminal::_4, stack.back().state), std::move(pushitem), NonTerminal::_4);
                        }
                        break;
                }
                break;
            case 71:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                    case TokenType::BANG:
                    case TokenType::BININTLIT:
                    case TokenType::CCURB:
                    case TokenType::CHARLIT:
                    case TokenType::DECINTLIT:
                    case TokenType::DEDENT:
                    case TokenType::EOF_:
                    case TokenType::FALSELIT:
                    case TokenType::FLOATLIT:
                    case TokenType::FUN:
                    case TokenType::HEXINTLIT:
                    case TokenType::IDENTIFIER:
                    case TokenType::IF:
                    case TokenType::IMPL:
                    case TokenType::MINUS:
                    case TokenType::NULLPTRLIT:
                    case TokenType::OCTINTLIT:
                    case TokenType::OCURB:
                    case TokenType::OPARN:
                    case TokenType::RETURN:
                    case TokenType::STAR:
                    case TokenType::STRINGLIT:
                    case TokenType::THIS:
                    case TokenType::TILDE:
                    case TokenType::TRUELIT:
                    case TokenType::VAR:
                    case TokenType::WHILE:
{
                            std::unique_ptr<ASTNS::PureLocation> pushitem = nullptr;
                            stack.emplace_back(get_goto(NonTerminal::_70, stack.back().state), std::move(pushitem), NonTerminal::_70);
                        }
                        break;
                    case TokenType::NEWLINE:
                        shift(p, lasttok, lookahead, stack, steps, 38); break;
                    case TokenType::SEMICOLON:
                        shift(p, lasttok, lookahead, stack, steps, 39); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "optional line ending", "function declaration")  });
                }
                break;
            case 72:
                switch (lookahead.type) {
                    default: {
                            auto a6 (pop_a<ASTNS::PureLocation>(stack));
                            auto a5 (pop_a<ASTNS::Type>(stack));
                            auto a4 (pop_t(stack));
                            auto a3 (pop_a<ASTNS::ParamList>(stack));
                            auto a2 (pop_t(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                a6 ? Maybe(a6->end()) :
                                a5 ? Maybe(a5->end()) :
                                Maybe<Location const>(a4);
std::unique_ptr<ASTNS::FunctionDecl> push (std::make_unique<ASTNS::FunctionDecl>(p.sourcefile, start, end, std::move(a5), a1, std::move(a3->params), nullptr));
                            std::unique_ptr<ASTNS::FunctionDecl> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_2, stack.back().state), std::move(pushitem), NonTerminal::_2);
                        }
                        break;
                }
                break;
            case 73:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::Block>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::Block> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_12, stack.back().state), std::move(pushitem), NonTerminal::_12);
                        }
                        break;
                }
                break;
            case 74:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::Block>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::Block> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_12, stack.back().state), std::move(pushitem), NonTerminal::_12);
                        }
                        break;
                }
                break;
            case 75:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                Maybe<Location const>(a0);
std::unique_ptr<ASTNS::PureLocation> push (std::make_unique<ASTNS::PureLocation>(p.sourcefile, start, end, 0));
                            std::unique_ptr<ASTNS::PureLocation> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_11, stack.back().state), std::move(pushitem), NonTerminal::_11);
                        }
                        break;
                    case TokenType::INDENT:
                        shift(p, lasttok, lookahead, stack, steps, 79); break;
                }
                break;
            case 76:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                        shift(p, lasttok, lookahead, stack, steps, 112); break;
                    case TokenType::BANG:
                        shift(p, lasttok, lookahead, stack, steps, 111); break;
                    case TokenType::BININTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 124); break;
                    case TokenType::CCURB:
                    case TokenType::DEDENT:
{
std::unique_ptr<ASTNS::StmtList> push (std::make_unique<ASTNS::StmtList>(p.sourcefile, Maybe<Location const>(), Maybe<Location const>(), std::vector<std::unique_ptr<ASTNS::Stmt>> {}));
                            std::unique_ptr<ASTNS::StmtList> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_66, stack.back().state), std::move(pushitem), NonTerminal::_66);
                        }
                        break;
                    case TokenType::CHARLIT:
                        shift(p, lasttok, lookahead, stack, steps, 126); break;
                    case TokenType::DECINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 122); break;
                    case TokenType::FALSELIT:
                        shift(p, lasttok, lookahead, stack, steps, 119); break;
                    case TokenType::FLOATLIT:
                        shift(p, lasttok, lookahead, stack, steps, 120); break;
                    case TokenType::HEXINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 125); break;
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::IF:
                        shift(p, lasttok, lookahead, stack, steps, 96); break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 110); break;
                    case TokenType::NEWLINE:
                        shift(p, lasttok, lookahead, stack, steps, 81); break;
                    case TokenType::NULLPTRLIT:
                        shift(p, lasttok, lookahead, stack, steps, 121); break;
                    case TokenType::OCTINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 123); break;
                    case TokenType::OCURB:
                        shift(p, lasttok, lookahead, stack, steps, 76); break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 129); break;
                    case TokenType::RETURN:
                        shift(p, lasttok, lookahead, stack, steps, 90); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 113); break;
                    case TokenType::STRINGLIT:
                        shift(p, lasttok, lookahead, stack, steps, 127); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 128); break;
                    case TokenType::TILDE:
                        shift(p, lasttok, lookahead, stack, steps, 109); break;
                    case TokenType::TRUELIT:
                        shift(p, lasttok, lookahead, stack, steps, 118); break;
                    case TokenType::VAR:
                        shift(p, lasttok, lookahead, stack, steps, 87); break;
                    case TokenType::WHILE:
                        shift(p, lasttok, lookahead, stack, steps, 97); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", format("either {} or {}", "optional statement list", stringify_token_type(TokenType::NEWLINE)), "braced code block")  });
                }
                break;
            case 77:
                switch (lookahead.type) {
                    case TokenType::CCURB:
                        shift(p, lasttok, lookahead, stack, steps, 132); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", stringify_token_type(TokenType::CCURB), "implementation body")  });
                }
                break;
            case 78:
                switch (lookahead.type) {
                    default: {
                            auto a7 (pop_a<ASTNS::PureLocation>(stack));
                            auto a6 (pop_a<ASTNS::Block>(stack));
                            auto a5 (pop_a<ASTNS::Type>(stack));
                            auto a4 (pop_t(stack));
                            auto a3 (pop_a<ASTNS::ParamList>(stack));
                            auto a2 (pop_t(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                a5 ? Maybe(a5->end()) :
                                Maybe<Location const>(a4);
std::unique_ptr<ASTNS::FunctionDecl> push (std::make_unique<ASTNS::FunctionDecl>(p.sourcefile, start, end, std::move(a5), a1, std::move(a3->params), std::move(a6)));
                            std::unique_ptr<ASTNS::FunctionDecl> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_2, stack.back().state), std::move(pushitem), NonTerminal::_2);
                        }
                        break;
                }
                break;
            case 79:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                        shift(p, lasttok, lookahead, stack, steps, 112); break;
                    case TokenType::BANG:
                        shift(p, lasttok, lookahead, stack, steps, 111); break;
                    case TokenType::BININTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 124); break;
                    case TokenType::CCURB:
                    case TokenType::DEDENT:
{
std::unique_ptr<ASTNS::StmtList> push (std::make_unique<ASTNS::StmtList>(p.sourcefile, Maybe<Location const>(), Maybe<Location const>(), std::vector<std::unique_ptr<ASTNS::Stmt>> {}));
                            std::unique_ptr<ASTNS::StmtList> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_66, stack.back().state), std::move(pushitem), NonTerminal::_66);
                        }
                        break;
                    case TokenType::CHARLIT:
                        shift(p, lasttok, lookahead, stack, steps, 126); break;
                    case TokenType::DECINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 122); break;
                    case TokenType::FALSELIT:
                        shift(p, lasttok, lookahead, stack, steps, 119); break;
                    case TokenType::FLOATLIT:
                        shift(p, lasttok, lookahead, stack, steps, 120); break;
                    case TokenType::HEXINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 125); break;
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::IF:
                        shift(p, lasttok, lookahead, stack, steps, 96); break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 110); break;
                    case TokenType::NULLPTRLIT:
                        shift(p, lasttok, lookahead, stack, steps, 121); break;
                    case TokenType::OCTINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 123); break;
                    case TokenType::OCURB:
                        shift(p, lasttok, lookahead, stack, steps, 76); break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 129); break;
                    case TokenType::RETURN:
                        shift(p, lasttok, lookahead, stack, steps, 90); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 113); break;
                    case TokenType::STRINGLIT:
                        shift(p, lasttok, lookahead, stack, steps, 127); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 128); break;
                    case TokenType::TILDE:
                        shift(p, lasttok, lookahead, stack, steps, 109); break;
                    case TokenType::TRUELIT:
                        shift(p, lasttok, lookahead, stack, steps, 118); break;
                    case TokenType::VAR:
                        shift(p, lasttok, lookahead, stack, steps, 87); break;
                    case TokenType::WHILE:
                        shift(p, lasttok, lookahead, stack, steps, 97); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "optional statement list", "indented code block")  });
                }
                break;
            case 80:
                switch (lookahead.type) {
                    case TokenType::CCURB:
                        shift(p, lasttok, lookahead, stack, steps, 134); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", stringify_token_type(TokenType::CCURB), "braced code block")  });
                }
                break;
            case 81:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                        shift(p, lasttok, lookahead, stack, steps, 112); break;
                    case TokenType::BANG:
                        shift(p, lasttok, lookahead, stack, steps, 111); break;
                    case TokenType::BININTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 124); break;
                    case TokenType::CCURB:
                    case TokenType::DEDENT:
{
std::unique_ptr<ASTNS::StmtList> push (std::make_unique<ASTNS::StmtList>(p.sourcefile, Maybe<Location const>(), Maybe<Location const>(), std::vector<std::unique_ptr<ASTNS::Stmt>> {}));
                            std::unique_ptr<ASTNS::StmtList> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_66, stack.back().state), std::move(pushitem), NonTerminal::_66);
                        }
                        break;
                    case TokenType::CHARLIT:
                        shift(p, lasttok, lookahead, stack, steps, 126); break;
                    case TokenType::DECINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 122); break;
                    case TokenType::FALSELIT:
                        shift(p, lasttok, lookahead, stack, steps, 119); break;
                    case TokenType::FLOATLIT:
                        shift(p, lasttok, lookahead, stack, steps, 120); break;
                    case TokenType::HEXINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 125); break;
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::IF:
                        shift(p, lasttok, lookahead, stack, steps, 96); break;
                    case TokenType::INDENT:
                        shift(p, lasttok, lookahead, stack, steps, 136); break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 110); break;
                    case TokenType::NULLPTRLIT:
                        shift(p, lasttok, lookahead, stack, steps, 121); break;
                    case TokenType::OCTINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 123); break;
                    case TokenType::OCURB:
                        shift(p, lasttok, lookahead, stack, steps, 76); break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 129); break;
                    case TokenType::RETURN:
                        shift(p, lasttok, lookahead, stack, steps, 90); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 113); break;
                    case TokenType::STRINGLIT:
                        shift(p, lasttok, lookahead, stack, steps, 127); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 128); break;
                    case TokenType::TILDE:
                        shift(p, lasttok, lookahead, stack, steps, 109); break;
                    case TokenType::TRUELIT:
                        shift(p, lasttok, lookahead, stack, steps, 118); break;
                    case TokenType::VAR:
                        shift(p, lasttok, lookahead, stack, steps, 87); break;
                    case TokenType::WHILE:
                        shift(p, lasttok, lookahead, stack, steps, 97); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", format("either {} or {}", "optional statement list", stringify_token_type(TokenType::INDENT)), "braced code block")  });
                }
                break;
            case 82:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                        shift(p, lasttok, lookahead, stack, steps, 112); break;
                    case TokenType::BANG:
                        shift(p, lasttok, lookahead, stack, steps, 111); break;
                    case TokenType::BININTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 124); break;
                    default: {
                            auto a0 (pop_a<ASTNS::StmtList>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::StmtList> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_66, stack.back().state), std::move(pushitem), NonTerminal::_66);
                        }
                        break;
                    case TokenType::CHARLIT:
                        shift(p, lasttok, lookahead, stack, steps, 126); break;
                    case TokenType::DECINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 122); break;
                    case TokenType::FALSELIT:
                        shift(p, lasttok, lookahead, stack, steps, 119); break;
                    case TokenType::FLOATLIT:
                        shift(p, lasttok, lookahead, stack, steps, 120); break;
                    case TokenType::HEXINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 125); break;
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::IF:
                        shift(p, lasttok, lookahead, stack, steps, 96); break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 110); break;
                    case TokenType::NULLPTRLIT:
                        shift(p, lasttok, lookahead, stack, steps, 121); break;
                    case TokenType::OCTINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 123); break;
                    case TokenType::OCURB:
                        shift(p, lasttok, lookahead, stack, steps, 76); break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 129); break;
                    case TokenType::RETURN:
                        shift(p, lasttok, lookahead, stack, steps, 90); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 113); break;
                    case TokenType::STRINGLIT:
                        shift(p, lasttok, lookahead, stack, steps, 127); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 128); break;
                    case TokenType::TILDE:
                        shift(p, lasttok, lookahead, stack, steps, 109); break;
                    case TokenType::TRUELIT:
                        shift(p, lasttok, lookahead, stack, steps, 118); break;
                    case TokenType::VAR:
                        shift(p, lasttok, lookahead, stack, steps, 87); break;
                    case TokenType::WHILE:
                        shift(p, lasttok, lookahead, stack, steps, 97); break;
                }
                break;
            case 83:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::Stmt>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
std::unique_ptr<ASTNS::StmtList> push(std::make_unique<ASTNS::StmtList>(p.sourcefile, start, end, std::vector<std::unique_ptr<ASTNS::Stmt>> {}));

        push->stmts.push_back(std::move(a0));
                            std::unique_ptr<ASTNS::StmtList> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_59, stack.back().state), std::move(pushitem), NonTerminal::_59);
                        }
                        break;
                }
                break;
            case 84:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::VarStmt>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::Stmt> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_6, stack.back().state), std::move(pushitem), NonTerminal::_6);
                        }
                        break;
                }
                break;
            case 85:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::ExprStmt>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::Stmt> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_6, stack.back().state), std::move(pushitem), NonTerminal::_6);
                        }
                        break;
                }
                break;
            case 86:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::RetStmt>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::Stmt> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_6, stack.back().state), std::move(pushitem), NonTerminal::_6);
                        }
                        break;
                }
                break;
            case 87:
                switch (lookahead.type) {
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 142); break;
                    case TokenType::MUT:
                        shift(p, lasttok, lookahead, stack, steps, 143); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "variable binding list", "variable declaration")  });
                }
                break;
            case 88:
                switch (lookahead.type) {
                    case TokenType::DOLLAR:
                        shift(p, lasttok, lookahead, stack, steps, 145); break;
                    case TokenType::NEWLINE:
                        shift(p, lasttok, lookahead, stack, steps, 38); break;
                    case TokenType::SEMICOLON:
                        shift(p, lasttok, lookahead, stack, steps, 39); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", format("either {} or {}", "line ending", stringify_token_type(TokenType::DOLLAR)), "expression statement")  });
                }
                break;
            case 89:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                    case TokenType::BANG:
                    case TokenType::BININTLIT:
                    case TokenType::CCURB:
                    case TokenType::CHARLIT:
                    case TokenType::DECINTLIT:
                    case TokenType::DEDENT:
                    case TokenType::EOF_:
                    case TokenType::FALSELIT:
                    case TokenType::FLOATLIT:
                    case TokenType::FUN:
                    case TokenType::HEXINTLIT:
                    case TokenType::IDENTIFIER:
                    case TokenType::IF:
                    case TokenType::IMPL:
                    case TokenType::MINUS:
                    case TokenType::NULLPTRLIT:
                    case TokenType::OCTINTLIT:
                    case TokenType::OCURB:
                    case TokenType::OPARN:
                    case TokenType::RETURN:
                    case TokenType::STAR:
                    case TokenType::STRINGLIT:
                    case TokenType::THIS:
                    case TokenType::TILDE:
                    case TokenType::TRUELIT:
                    case TokenType::VAR:
                    case TokenType::WHILE:
{
                            std::unique_ptr<ASTNS::PureLocation> pushitem = nullptr;
                            stack.emplace_back(get_goto(NonTerminal::_70, stack.back().state), std::move(pushitem), NonTerminal::_70);
                        }
                        break;
                    case TokenType::DOLLAR:
                        shift(p, lasttok, lookahead, stack, steps, 147); break;
                    case TokenType::NEWLINE:
                        shift(p, lasttok, lookahead, stack, steps, 38); break;
                    case TokenType::SEMICOLON:
                        shift(p, lasttok, lookahead, stack, steps, 39); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", format("either {} or {}", "optional line ending", stringify_token_type(TokenType::DOLLAR)), "expression statement")  });
                }
                break;
            case 90:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                        shift(p, lasttok, lookahead, stack, steps, 112); break;
                    case TokenType::BANG:
                        shift(p, lasttok, lookahead, stack, steps, 111); break;
                    case TokenType::BININTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 124); break;
                    case TokenType::CHARLIT:
                        shift(p, lasttok, lookahead, stack, steps, 126); break;
                    case TokenType::DECINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 122); break;
                    case TokenType::FALSELIT:
                        shift(p, lasttok, lookahead, stack, steps, 119); break;
                    case TokenType::FLOATLIT:
                        shift(p, lasttok, lookahead, stack, steps, 120); break;
                    case TokenType::HEXINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 125); break;
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::IF:
                        shift(p, lasttok, lookahead, stack, steps, 96); break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 110); break;
                    case TokenType::NEWLINE:
                        shift(p, lasttok, lookahead, stack, steps, 38); break;
                    case TokenType::NULLPTRLIT:
                        shift(p, lasttok, lookahead, stack, steps, 121); break;
                    case TokenType::OCTINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 123); break;
                    case TokenType::OCURB:
                        shift(p, lasttok, lookahead, stack, steps, 76); break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 129); break;
                    case TokenType::SEMICOLON:
                        shift(p, lasttok, lookahead, stack, steps, 39); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 113); break;
                    case TokenType::STRINGLIT:
                        shift(p, lasttok, lookahead, stack, steps, 127); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 128); break;
                    case TokenType::TILDE:
                        shift(p, lasttok, lookahead, stack, steps, 109); break;
                    case TokenType::TRUELIT:
                        shift(p, lasttok, lookahead, stack, steps, 118); break;
                    case TokenType::WHILE:
                        shift(p, lasttok, lookahead, stack, steps, 97); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", format("either {} or {}", "expression", "line ending"), "return statement")  });
                }
                break;
            case 91:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_26, stack.back().state), std::move(pushitem), NonTerminal::_26);
                        }
                        break;
                }
                break;
            case 92:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::IfExpr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_25, stack.back().state), std::move(pushitem), NonTerminal::_25);
                        }
                        break;
                }
                break;
            case 93:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::WhileExpr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_25, stack.back().state), std::move(pushitem), NonTerminal::_25);
                        }
                        break;
                }
                break;
            case 94:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::Block>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_25, stack.back().state), std::move(pushitem), NonTerminal::_25);
                        }
                        break;
                }
                break;
            case 95:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_29, stack.back().state), std::move(pushitem), NonTerminal::_29);
                        }
                        break;
                    case TokenType::DOUBLEPIPE:
                        shift(p, lasttok, lookahead, stack, steps, 153); break;
                    case TokenType::EQUAL:
                        shift(p, lasttok, lookahead, stack, steps, 152); break;
                }
                break;
            case 96:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                        shift(p, lasttok, lookahead, stack, steps, 112); break;
                    case TokenType::BANG:
                        shift(p, lasttok, lookahead, stack, steps, 111); break;
                    case TokenType::BININTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 124); break;
                    case TokenType::CHARLIT:
                        shift(p, lasttok, lookahead, stack, steps, 126); break;
                    case TokenType::DECINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 122); break;
                    case TokenType::FALSELIT:
                        shift(p, lasttok, lookahead, stack, steps, 119); break;
                    case TokenType::FLOATLIT:
                        shift(p, lasttok, lookahead, stack, steps, 120); break;
                    case TokenType::HEXINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 125); break;
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::IF:
                        shift(p, lasttok, lookahead, stack, steps, 96); break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 110); break;
                    case TokenType::NULLPTRLIT:
                        shift(p, lasttok, lookahead, stack, steps, 121); break;
                    case TokenType::OCTINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 123); break;
                    case TokenType::OCURB:
                        shift(p, lasttok, lookahead, stack, steps, 76); break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 129); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 113); break;
                    case TokenType::STRINGLIT:
                        shift(p, lasttok, lookahead, stack, steps, 127); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 128); break;
                    case TokenType::TILDE:
                        shift(p, lasttok, lookahead, stack, steps, 109); break;
                    case TokenType::TRUELIT:
                        shift(p, lasttok, lookahead, stack, steps, 118); break;
                    case TokenType::WHILE:
                        shift(p, lasttok, lookahead, stack, steps, 97); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "expression", "if expression")  });
                }
                break;
            case 97:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                        shift(p, lasttok, lookahead, stack, steps, 112); break;
                    case TokenType::BANG:
                        shift(p, lasttok, lookahead, stack, steps, 111); break;
                    case TokenType::BININTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 124); break;
                    case TokenType::CHARLIT:
                        shift(p, lasttok, lookahead, stack, steps, 126); break;
                    case TokenType::DECINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 122); break;
                    case TokenType::FALSELIT:
                        shift(p, lasttok, lookahead, stack, steps, 119); break;
                    case TokenType::FLOATLIT:
                        shift(p, lasttok, lookahead, stack, steps, 120); break;
                    case TokenType::HEXINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 125); break;
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::IF:
                        shift(p, lasttok, lookahead, stack, steps, 96); break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 110); break;
                    case TokenType::NULLPTRLIT:
                        shift(p, lasttok, lookahead, stack, steps, 121); break;
                    case TokenType::OCTINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 123); break;
                    case TokenType::OCURB:
                        shift(p, lasttok, lookahead, stack, steps, 76); break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 129); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 113); break;
                    case TokenType::STRINGLIT:
                        shift(p, lasttok, lookahead, stack, steps, 127); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 128); break;
                    case TokenType::TILDE:
                        shift(p, lasttok, lookahead, stack, steps, 109); break;
                    case TokenType::TRUELIT:
                        shift(p, lasttok, lookahead, stack, steps, 118); break;
                    case TokenType::WHILE:
                        shift(p, lasttok, lookahead, stack, steps, 97); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "expression", "while loop expression")  });
                }
                break;
            case 98:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_30, stack.back().state), std::move(pushitem), NonTerminal::_30);
                        }
                        break;
                    case TokenType::DOUBLEAMPER:
                        shift(p, lasttok, lookahead, stack, steps, 156); break;
                }
                break;
            case 99:
                switch (lookahead.type) {
                    case TokenType::BANGEQUAL:
                        shift(p, lasttok, lookahead, stack, steps, 157); break;
                    default: {
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_31, stack.back().state), std::move(pushitem), NonTerminal::_31);
                        }
                        break;
                    case TokenType::DOUBLEEQUAL:
                        shift(p, lasttok, lookahead, stack, steps, 158); break;
                }
                break;
            case 100:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_32, stack.back().state), std::move(pushitem), NonTerminal::_32);
                        }
                        break;
                    case TokenType::GREATER:
                        shift(p, lasttok, lookahead, stack, steps, 160); break;
                    case TokenType::GREATEREQUAL:
                        shift(p, lasttok, lookahead, stack, steps, 162); break;
                    case TokenType::LESS:
                        shift(p, lasttok, lookahead, stack, steps, 159); break;
                    case TokenType::LESSEQUAL:
                        shift(p, lasttok, lookahead, stack, steps, 161); break;
                }
                break;
            case 101:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_33, stack.back().state), std::move(pushitem), NonTerminal::_33);
                        }
                        break;
                    case TokenType::CARET:
                        shift(p, lasttok, lookahead, stack, steps, 163); break;
                }
                break;
            case 102:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_34, stack.back().state), std::move(pushitem), NonTerminal::_34);
                        }
                        break;
                    case TokenType::PIPE:
                        shift(p, lasttok, lookahead, stack, steps, 164); break;
                }
                break;
            case 103:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                        shift(p, lasttok, lookahead, stack, steps, 165); break;
                    default: {
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_35, stack.back().state), std::move(pushitem), NonTerminal::_35);
                        }
                        break;
                }
                break;
            case 104:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_36, stack.back().state), std::move(pushitem), NonTerminal::_36);
                        }
                        break;
                    case TokenType::DOUBLEGREATER:
                        shift(p, lasttok, lookahead, stack, steps, 166); break;
                    case TokenType::DOUBLELESS:
                        shift(p, lasttok, lookahead, stack, steps, 167); break;
                }
                break;
            case 105:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_37, stack.back().state), std::move(pushitem), NonTerminal::_37);
                        }
                        break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 169); break;
                    case TokenType::PLUS:
                        shift(p, lasttok, lookahead, stack, steps, 168); break;
                }
                break;
            case 106:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_38, stack.back().state), std::move(pushitem), NonTerminal::_38);
                        }
                        break;
                    case TokenType::PERCENT:
                        shift(p, lasttok, lookahead, stack, steps, 172); break;
                    case TokenType::SLASH:
                        shift(p, lasttok, lookahead, stack, steps, 171); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 170); break;
                }
                break;
            case 107:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_39, stack.back().state), std::move(pushitem), NonTerminal::_39);
                        }
                        break;
                    case TokenType::RIGHTARROW:
                        shift(p, lasttok, lookahead, stack, steps, 173); break;
                }
                break;
            case 108:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_40, stack.back().state), std::move(pushitem), NonTerminal::_40);
                        }
                        break;
                }
                break;
            case 109:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                        shift(p, lasttok, lookahead, stack, steps, 112); break;
                    case TokenType::BANG:
                        shift(p, lasttok, lookahead, stack, steps, 111); break;
                    case TokenType::BININTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 124); break;
                    case TokenType::CHARLIT:
                        shift(p, lasttok, lookahead, stack, steps, 126); break;
                    case TokenType::DECINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 122); break;
                    case TokenType::FALSELIT:
                        shift(p, lasttok, lookahead, stack, steps, 119); break;
                    case TokenType::FLOATLIT:
                        shift(p, lasttok, lookahead, stack, steps, 120); break;
                    case TokenType::HEXINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 125); break;
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 110); break;
                    case TokenType::NULLPTRLIT:
                        shift(p, lasttok, lookahead, stack, steps, 121); break;
                    case TokenType::OCTINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 123); break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 129); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 113); break;
                    case TokenType::STRINGLIT:
                        shift(p, lasttok, lookahead, stack, steps, 127); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 128); break;
                    case TokenType::TILDE:
                        shift(p, lasttok, lookahead, stack, steps, 109); break;
                    case TokenType::TRUELIT:
                        shift(p, lasttok, lookahead, stack, steps, 118); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "unary expression", "unary expression")  });
                }
                break;
            case 110:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                        shift(p, lasttok, lookahead, stack, steps, 112); break;
                    case TokenType::BANG:
                        shift(p, lasttok, lookahead, stack, steps, 111); break;
                    case TokenType::BININTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 124); break;
                    case TokenType::CHARLIT:
                        shift(p, lasttok, lookahead, stack, steps, 126); break;
                    case TokenType::DECINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 122); break;
                    case TokenType::FALSELIT:
                        shift(p, lasttok, lookahead, stack, steps, 119); break;
                    case TokenType::FLOATLIT:
                        shift(p, lasttok, lookahead, stack, steps, 120); break;
                    case TokenType::HEXINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 125); break;
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 110); break;
                    case TokenType::NULLPTRLIT:
                        shift(p, lasttok, lookahead, stack, steps, 121); break;
                    case TokenType::OCTINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 123); break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 129); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 113); break;
                    case TokenType::STRINGLIT:
                        shift(p, lasttok, lookahead, stack, steps, 127); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 128); break;
                    case TokenType::TILDE:
                        shift(p, lasttok, lookahead, stack, steps, 109); break;
                    case TokenType::TRUELIT:
                        shift(p, lasttok, lookahead, stack, steps, 118); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "unary expression", "unary expression")  });
                }
                break;
            case 111:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                        shift(p, lasttok, lookahead, stack, steps, 112); break;
                    case TokenType::BANG:
                        shift(p, lasttok, lookahead, stack, steps, 111); break;
                    case TokenType::BININTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 124); break;
                    case TokenType::CHARLIT:
                        shift(p, lasttok, lookahead, stack, steps, 126); break;
                    case TokenType::DECINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 122); break;
                    case TokenType::FALSELIT:
                        shift(p, lasttok, lookahead, stack, steps, 119); break;
                    case TokenType::FLOATLIT:
                        shift(p, lasttok, lookahead, stack, steps, 120); break;
                    case TokenType::HEXINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 125); break;
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 110); break;
                    case TokenType::NULLPTRLIT:
                        shift(p, lasttok, lookahead, stack, steps, 121); break;
                    case TokenType::OCTINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 123); break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 129); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 113); break;
                    case TokenType::STRINGLIT:
                        shift(p, lasttok, lookahead, stack, steps, 127); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 128); break;
                    case TokenType::TILDE:
                        shift(p, lasttok, lookahead, stack, steps, 109); break;
                    case TokenType::TRUELIT:
                        shift(p, lasttok, lookahead, stack, steps, 118); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "unary expression", "unary expression")  });
                }
                break;
            case 112:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                        shift(p, lasttok, lookahead, stack, steps, 112); break;
                    case TokenType::BANG:
                        shift(p, lasttok, lookahead, stack, steps, 111); break;
                    case TokenType::BININTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 124); break;
                    case TokenType::CHARLIT:
                        shift(p, lasttok, lookahead, stack, steps, 126); break;
                    case TokenType::DECINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 122); break;
                    case TokenType::FALSELIT:
                        shift(p, lasttok, lookahead, stack, steps, 119); break;
                    case TokenType::FLOATLIT:
                        shift(p, lasttok, lookahead, stack, steps, 120); break;
                    case TokenType::HEXINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 125); break;
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 110); break;
                    case TokenType::MUT:
                        shift(p, lasttok, lookahead, stack, steps, 178); break;
                    case TokenType::NULLPTRLIT:
                        shift(p, lasttok, lookahead, stack, steps, 121); break;
                    case TokenType::OCTINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 123); break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 129); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 113); break;
                    case TokenType::STRINGLIT:
                        shift(p, lasttok, lookahead, stack, steps, 127); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 128); break;
                    case TokenType::TILDE:
                        shift(p, lasttok, lookahead, stack, steps, 109); break;
                    case TokenType::TRUELIT:
                        shift(p, lasttok, lookahead, stack, steps, 118); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", format("either {} or {}", "unary expression", stringify_token_type(TokenType::MUT)), "unary expression")  });
                }
                break;
            case 113:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                        shift(p, lasttok, lookahead, stack, steps, 112); break;
                    case TokenType::BANG:
                        shift(p, lasttok, lookahead, stack, steps, 111); break;
                    case TokenType::BININTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 124); break;
                    case TokenType::CHARLIT:
                        shift(p, lasttok, lookahead, stack, steps, 126); break;
                    case TokenType::DECINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 122); break;
                    case TokenType::FALSELIT:
                        shift(p, lasttok, lookahead, stack, steps, 119); break;
                    case TokenType::FLOATLIT:
                        shift(p, lasttok, lookahead, stack, steps, 120); break;
                    case TokenType::HEXINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 125); break;
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 110); break;
                    case TokenType::NULLPTRLIT:
                        shift(p, lasttok, lookahead, stack, steps, 121); break;
                    case TokenType::OCTINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 123); break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 129); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 113); break;
                    case TokenType::STRINGLIT:
                        shift(p, lasttok, lookahead, stack, steps, 127); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 128); break;
                    case TokenType::TILDE:
                        shift(p, lasttok, lookahead, stack, steps, 109); break;
                    case TokenType::TRUELIT:
                        shift(p, lasttok, lookahead, stack, steps, 118); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "unary expression", "unary expression")  });
                }
                break;
            case 114:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_41, stack.back().state), std::move(pushitem), NonTerminal::_41);
                        }
                        break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 180); break;
                    case TokenType::PERIOD:
                        shift(p, lasttok, lookahead, stack, steps, 181); break;
                }
                break;
            case 115:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_41, stack.back().state), std::move(pushitem), NonTerminal::_41);
                        }
                        break;
                    case TokenType::PERIOD:
                        shift(p, lasttok, lookahead, stack, steps, 182); break;
                }
                break;
            case 116:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_41, stack.back().state), std::move(pushitem), NonTerminal::_41);
                        }
                        break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 183); break;
                    case TokenType::PERIOD:
                        shift(p, lasttok, lookahead, stack, steps, 184); break;
                }
                break;
            case 117:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_42, stack.back().state), std::move(pushitem), NonTerminal::_42);
                        }
                        break;
                }
                break;
            case 118:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                Maybe<Location const>(a0);
std::unique_ptr<ASTNS::PrimaryExpr> push (std::make_unique<ASTNS::PrimaryExpr>(p.sourcefile, start, end, a0));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_45, stack.back().state), std::move(pushitem), NonTerminal::_45);
                        }
                        break;
                }
                break;
            case 119:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                Maybe<Location const>(a0);
std::unique_ptr<ASTNS::PrimaryExpr> push (std::make_unique<ASTNS::PrimaryExpr>(p.sourcefile, start, end, a0));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_45, stack.back().state), std::move(pushitem), NonTerminal::_45);
                        }
                        break;
                }
                break;
            case 120:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                Maybe<Location const>(a0);
std::unique_ptr<ASTNS::PrimaryExpr> push (std::make_unique<ASTNS::PrimaryExpr>(p.sourcefile, start, end, a0));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_45, stack.back().state), std::move(pushitem), NonTerminal::_45);
                        }
                        break;
                }
                break;
            case 121:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                Maybe<Location const>(a0);
std::unique_ptr<ASTNS::PrimaryExpr> push (std::make_unique<ASTNS::PrimaryExpr>(p.sourcefile, start, end, a0));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_45, stack.back().state), std::move(pushitem), NonTerminal::_45);
                        }
                        break;
                }
                break;
            case 122:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                Maybe<Location const>(a0);
std::unique_ptr<ASTNS::PrimaryExpr> push (std::make_unique<ASTNS::PrimaryExpr>(p.sourcefile, start, end, a0));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_45, stack.back().state), std::move(pushitem), NonTerminal::_45);
                        }
                        break;
                }
                break;
            case 123:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                Maybe<Location const>(a0);
std::unique_ptr<ASTNS::PrimaryExpr> push (std::make_unique<ASTNS::PrimaryExpr>(p.sourcefile, start, end, a0));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_45, stack.back().state), std::move(pushitem), NonTerminal::_45);
                        }
                        break;
                }
                break;
            case 124:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                Maybe<Location const>(a0);
std::unique_ptr<ASTNS::PrimaryExpr> push (std::make_unique<ASTNS::PrimaryExpr>(p.sourcefile, start, end, a0));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_45, stack.back().state), std::move(pushitem), NonTerminal::_45);
                        }
                        break;
                }
                break;
            case 125:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                Maybe<Location const>(a0);
std::unique_ptr<ASTNS::PrimaryExpr> push (std::make_unique<ASTNS::PrimaryExpr>(p.sourcefile, start, end, a0));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_45, stack.back().state), std::move(pushitem), NonTerminal::_45);
                        }
                        break;
                }
                break;
            case 126:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                Maybe<Location const>(a0);
std::unique_ptr<ASTNS::PrimaryExpr> push (std::make_unique<ASTNS::PrimaryExpr>(p.sourcefile, start, end, a0));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_45, stack.back().state), std::move(pushitem), NonTerminal::_45);
                        }
                        break;
                }
                break;
            case 127:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                Maybe<Location const>(a0);
std::unique_ptr<ASTNS::PrimaryExpr> push (std::make_unique<ASTNS::PrimaryExpr>(p.sourcefile, start, end, a0));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_45, stack.back().state), std::move(pushitem), NonTerminal::_45);
                        }
                        break;
                }
                break;
            case 128:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                Maybe<Location const>(a0);
std::unique_ptr<ASTNS::PrimaryExpr> push (std::make_unique<ASTNS::PrimaryExpr>(p.sourcefile, start, end, a0));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_45, stack.back().state), std::move(pushitem), NonTerminal::_45);
                        }
                        break;
                }
                break;
            case 129:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                        shift(p, lasttok, lookahead, stack, steps, 112); break;
                    case TokenType::BANG:
                        shift(p, lasttok, lookahead, stack, steps, 111); break;
                    case TokenType::BININTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 124); break;
                    case TokenType::CHARLIT:
                        shift(p, lasttok, lookahead, stack, steps, 126); break;
                    case TokenType::DECINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 122); break;
                    case TokenType::FALSELIT:
                        shift(p, lasttok, lookahead, stack, steps, 119); break;
                    case TokenType::FLOATLIT:
                        shift(p, lasttok, lookahead, stack, steps, 120); break;
                    case TokenType::HEXINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 125); break;
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::IF:
                        shift(p, lasttok, lookahead, stack, steps, 96); break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 110); break;
                    case TokenType::NULLPTRLIT:
                        shift(p, lasttok, lookahead, stack, steps, 121); break;
                    case TokenType::OCTINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 123); break;
                    case TokenType::OCURB:
                        shift(p, lasttok, lookahead, stack, steps, 76); break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 129); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 113); break;
                    case TokenType::STRINGLIT:
                        shift(p, lasttok, lookahead, stack, steps, 127); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 128); break;
                    case TokenType::TILDE:
                        shift(p, lasttok, lookahead, stack, steps, 109); break;
                    case TokenType::TRUELIT:
                        shift(p, lasttok, lookahead, stack, steps, 118); break;
                    case TokenType::WHILE:
                        shift(p, lasttok, lookahead, stack, steps, 97); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "expression", "primary expression")  });
                }
                break;
            case 130:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_45, stack.back().state), std::move(pushitem), NonTerminal::_45);
                        }
                        break;
                }
                break;
            case 131:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::Path>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
std::unique_ptr<ASTNS::PathExpr> push (std::make_unique<ASTNS::PathExpr>(p.sourcefile, start, end, std::move(a0)));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_46, stack.back().state), std::move(pushitem), NonTerminal::_46);
                        }
                        break;
                    case TokenType::DOUBLECOLON:
                        shift(p, lasttok, lookahead, stack, steps, 23); break;
                }
                break;
            case 132:
                switch (lookahead.type) {
                    default: {
                            auto a5 (pop_t(stack));
                            auto a4 (pop_t(stack));
                            auto a3 (pop_a<ASTNS::ImplMemberList>(stack));
                            auto a2 (pop_t(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                Maybe<Location const>(a5);
                            std::unique_ptr<ASTNS::ImplMemberList> pushitem = std::move(a3);
                            stack.emplace_back(get_goto(NonTerminal::_4, stack.back().state), std::move(pushitem), NonTerminal::_4);
                        }
                        break;
                }
                break;
            case 133:
                switch (lookahead.type) {
                    case TokenType::DEDENT:
                        shift(p, lasttok, lookahead, stack, steps, 186); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", stringify_token_type(TokenType::DEDENT), "indented code block")  });
                }
                break;
            case 134:
                switch (lookahead.type) {
                    default: {
                            auto a2 (pop_t(stack));
                            auto a1 (pop_a<ASTNS::StmtList>(stack));
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                Maybe<Location const>(a2);
std::unique_ptr<ASTNS::Block> push (std::make_unique<ASTNS::Block>(p.sourcefile, start, end, std::move(a1->stmts)));
                            std::unique_ptr<ASTNS::Block> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_13, stack.back().state), std::move(pushitem), NonTerminal::_13);
                        }
                        break;
                }
                break;
            case 135:
                switch (lookahead.type) {
                    case TokenType::CCURB:
                        shift(p, lasttok, lookahead, stack, steps, 187); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", stringify_token_type(TokenType::CCURB), "braced code block")  });
                }
                break;
            case 136:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                        shift(p, lasttok, lookahead, stack, steps, 112); break;
                    case TokenType::BANG:
                        shift(p, lasttok, lookahead, stack, steps, 111); break;
                    case TokenType::BININTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 124); break;
                    case TokenType::CCURB:
                    case TokenType::DEDENT:
{
std::unique_ptr<ASTNS::StmtList> push (std::make_unique<ASTNS::StmtList>(p.sourcefile, Maybe<Location const>(), Maybe<Location const>(), std::vector<std::unique_ptr<ASTNS::Stmt>> {}));
                            std::unique_ptr<ASTNS::StmtList> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_66, stack.back().state), std::move(pushitem), NonTerminal::_66);
                        }
                        break;
                    case TokenType::CHARLIT:
                        shift(p, lasttok, lookahead, stack, steps, 126); break;
                    case TokenType::DECINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 122); break;
                    case TokenType::FALSELIT:
                        shift(p, lasttok, lookahead, stack, steps, 119); break;
                    case TokenType::FLOATLIT:
                        shift(p, lasttok, lookahead, stack, steps, 120); break;
                    case TokenType::HEXINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 125); break;
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::IF:
                        shift(p, lasttok, lookahead, stack, steps, 96); break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 110); break;
                    case TokenType::NULLPTRLIT:
                        shift(p, lasttok, lookahead, stack, steps, 121); break;
                    case TokenType::OCTINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 123); break;
                    case TokenType::OCURB:
                        shift(p, lasttok, lookahead, stack, steps, 76); break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 129); break;
                    case TokenType::RETURN:
                        shift(p, lasttok, lookahead, stack, steps, 90); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 113); break;
                    case TokenType::STRINGLIT:
                        shift(p, lasttok, lookahead, stack, steps, 127); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 128); break;
                    case TokenType::TILDE:
                        shift(p, lasttok, lookahead, stack, steps, 109); break;
                    case TokenType::TRUELIT:
                        shift(p, lasttok, lookahead, stack, steps, 118); break;
                    case TokenType::VAR:
                        shift(p, lasttok, lookahead, stack, steps, 87); break;
                    case TokenType::WHILE:
                        shift(p, lasttok, lookahead, stack, steps, 97); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "optional statement list", "braced code block")  });
                }
                break;
            case 137:
                switch (lookahead.type) {
                    default: {
                            auto a1 (pop_a<ASTNS::Stmt>(stack));
                            auto a0 (pop_a<ASTNS::StmtList>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) :
                                a1 ? Maybe(a1->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a1 ? Maybe(a1->end()) :
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
a0->stmts.push_back(std::move(a1));
                            std::unique_ptr<ASTNS::StmtList> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_59, stack.back().state), std::move(pushitem), NonTerminal::_59);
                        }
                        break;
                }
                break;
            case 138:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::Stmt>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::Stmt> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_58, stack.back().state), std::move(pushitem), NonTerminal::_58);
                        }
                        break;
                }
                break;
            case 139:
                switch (lookahead.type) {
                    case TokenType::NEWLINE:
                        shift(p, lasttok, lookahead, stack, steps, 38); break;
                    case TokenType::SEMICOLON:
                        shift(p, lasttok, lookahead, stack, steps, 39); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "line ending", "variable declaration")  });
                }
                break;
            case 140:
                switch (lookahead.type) {
                    case TokenType::COMMA:
                        shift(p, lasttok, lookahead, stack, steps, 190); break;
                    default: {
                            auto a0 (pop_a<ASTNS::VarStmtItemList>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::VarStmtItemList> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_56, stack.back().state), std::move(pushitem), NonTerminal::_56);
                        }
                        break;
                }
                break;
            case 141:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::VarStmtItem>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
std::unique_ptr<ASTNS::VarStmtItemList> push(std::make_unique<ASTNS::VarStmtItemList>(p.sourcefile, start, end, std::vector<std::unique_ptr<ASTNS::VarStmtItem>> {}));

        push->items.push_back(std::move(a0));
                            std::unique_ptr<ASTNS::VarStmtItemList> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_57, stack.back().state), std::move(pushitem), NonTerminal::_57);
                        }
                        break;
                }
                break;
            case 142:
                switch (lookahead.type) {
                    case TokenType::COLON:
                        shift(p, lasttok, lookahead, stack, steps, 51); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "required type annotation", "variable binding")  });
                }
                break;
            case 143:
                switch (lookahead.type) {
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 192); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", stringify_token_type(TokenType::IDENTIFIER), "variable binding")  });
                }
                break;
            case 144:
                switch (lookahead.type) {
                    default: {
                            auto a1 (pop_a<ASTNS::PureLocation>(stack));
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) :
                                a1 ? Maybe(a1->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a1 ? Maybe(a1->end()) :
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
std::unique_ptr<ASTNS::ExprStmt> push (std::make_unique<ASTNS::ExprStmt>(p.sourcefile, start, end, std::move(a0), false, Maybe<Location const>()));
                            std::unique_ptr<ASTNS::ExprStmt> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_8, stack.back().state), std::move(pushitem), NonTerminal::_8);
                        }
                        break;
                }
                break;
            case 145:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                    case TokenType::BANG:
                    case TokenType::BININTLIT:
                    case TokenType::CCURB:
                    case TokenType::CHARLIT:
                    case TokenType::DECINTLIT:
                    case TokenType::DEDENT:
                    case TokenType::EOF_:
                    case TokenType::FALSELIT:
                    case TokenType::FLOATLIT:
                    case TokenType::FUN:
                    case TokenType::HEXINTLIT:
                    case TokenType::IDENTIFIER:
                    case TokenType::IF:
                    case TokenType::IMPL:
                    case TokenType::MINUS:
                    case TokenType::NULLPTRLIT:
                    case TokenType::OCTINTLIT:
                    case TokenType::OCURB:
                    case TokenType::OPARN:
                    case TokenType::RETURN:
                    case TokenType::STAR:
                    case TokenType::STRINGLIT:
                    case TokenType::THIS:
                    case TokenType::TILDE:
                    case TokenType::TRUELIT:
                    case TokenType::VAR:
                    case TokenType::WHILE:
{
                            std::unique_ptr<ASTNS::PureLocation> pushitem = nullptr;
                            stack.emplace_back(get_goto(NonTerminal::_70, stack.back().state), std::move(pushitem), NonTerminal::_70);
                        }
                        break;
                    case TokenType::NEWLINE:
                        shift(p, lasttok, lookahead, stack, steps, 38); break;
                    case TokenType::SEMICOLON:
                        shift(p, lasttok, lookahead, stack, steps, 39); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "optional line ending", "expression statement")  });
                }
                break;
            case 146:
                switch (lookahead.type) {
                    default: {
                            auto a1 (pop_a<ASTNS::PureLocation>(stack));
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) :
                                a1 ? Maybe(a1->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a1 ? Maybe(a1->end()) :
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
std::unique_ptr<ASTNS::ExprStmt> push (std::make_unique<ASTNS::ExprStmt>(p.sourcefile, start, end, std::move(a0), false, Maybe<Location const>()));
                            std::unique_ptr<ASTNS::ExprStmt> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_8, stack.back().state), std::move(pushitem), NonTerminal::_8);
                        }
                        break;
                }
                break;
            case 147:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                    case TokenType::BANG:
                    case TokenType::BININTLIT:
                    case TokenType::CCURB:
                    case TokenType::CHARLIT:
                    case TokenType::DECINTLIT:
                    case TokenType::DEDENT:
                    case TokenType::EOF_:
                    case TokenType::FALSELIT:
                    case TokenType::FLOATLIT:
                    case TokenType::FUN:
                    case TokenType::HEXINTLIT:
                    case TokenType::IDENTIFIER:
                    case TokenType::IF:
                    case TokenType::IMPL:
                    case TokenType::MINUS:
                    case TokenType::NULLPTRLIT:
                    case TokenType::OCTINTLIT:
                    case TokenType::OCURB:
                    case TokenType::OPARN:
                    case TokenType::RETURN:
                    case TokenType::STAR:
                    case TokenType::STRINGLIT:
                    case TokenType::THIS:
                    case TokenType::TILDE:
                    case TokenType::TRUELIT:
                    case TokenType::VAR:
                    case TokenType::WHILE:
{
                            std::unique_ptr<ASTNS::PureLocation> pushitem = nullptr;
                            stack.emplace_back(get_goto(NonTerminal::_70, stack.back().state), std::move(pushitem), NonTerminal::_70);
                        }
                        break;
                    case TokenType::NEWLINE:
                        shift(p, lasttok, lookahead, stack, steps, 38); break;
                    case TokenType::SEMICOLON:
                        shift(p, lasttok, lookahead, stack, steps, 39); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "optional line ending", "expression statement")  });
                }
                break;
            case 148:
                switch (lookahead.type) {
                    case TokenType::NEWLINE:
                        shift(p, lasttok, lookahead, stack, steps, 38); break;
                    case TokenType::SEMICOLON:
                        shift(p, lasttok, lookahead, stack, steps, 39); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "line ending", "return statement")  });
                }
                break;
            case 149:
                switch (lookahead.type) {
                    default: {
                            auto a1 (pop_a<ASTNS::PureLocation>(stack));
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                a1 ? Maybe(a1->end()) :
                                Maybe<Location const>(a0);
std::unique_ptr<ASTNS::RetStmt> push (std::make_unique<ASTNS::RetStmt>(p.sourcefile, start, end, nullptr));
                            std::unique_ptr<ASTNS::RetStmt> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_9, stack.back().state), std::move(pushitem), NonTerminal::_9);
                        }
                        break;
                }
                break;
            case 150:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_24, stack.back().state), std::move(pushitem), NonTerminal::_24);
                        }
                        break;
                }
                break;
            case 151:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_24, stack.back().state), std::move(pushitem), NonTerminal::_24);
                        }
                        break;
                }
                break;
            case 152:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                        shift(p, lasttok, lookahead, stack, steps, 112); break;
                    case TokenType::BANG:
                        shift(p, lasttok, lookahead, stack, steps, 111); break;
                    case TokenType::BININTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 124); break;
                    case TokenType::CHARLIT:
                        shift(p, lasttok, lookahead, stack, steps, 126); break;
                    case TokenType::DECINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 122); break;
                    case TokenType::FALSELIT:
                        shift(p, lasttok, lookahead, stack, steps, 119); break;
                    case TokenType::FLOATLIT:
                        shift(p, lasttok, lookahead, stack, steps, 120); break;
                    case TokenType::HEXINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 125); break;
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 110); break;
                    case TokenType::NULLPTRLIT:
                        shift(p, lasttok, lookahead, stack, steps, 121); break;
                    case TokenType::OCTINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 123); break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 129); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 113); break;
                    case TokenType::STRINGLIT:
                        shift(p, lasttok, lookahead, stack, steps, 127); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 128); break;
                    case TokenType::TILDE:
                        shift(p, lasttok, lookahead, stack, steps, 109); break;
                    case TokenType::TRUELIT:
                        shift(p, lasttok, lookahead, stack, steps, 118); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "assignment expression", "assignment expression")  });
                }
                break;
            case 153:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                        shift(p, lasttok, lookahead, stack, steps, 112); break;
                    case TokenType::BANG:
                        shift(p, lasttok, lookahead, stack, steps, 111); break;
                    case TokenType::BININTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 124); break;
                    case TokenType::CHARLIT:
                        shift(p, lasttok, lookahead, stack, steps, 126); break;
                    case TokenType::DECINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 122); break;
                    case TokenType::FALSELIT:
                        shift(p, lasttok, lookahead, stack, steps, 119); break;
                    case TokenType::FLOATLIT:
                        shift(p, lasttok, lookahead, stack, steps, 120); break;
                    case TokenType::HEXINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 125); break;
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 110); break;
                    case TokenType::NULLPTRLIT:
                        shift(p, lasttok, lookahead, stack, steps, 121); break;
                    case TokenType::OCTINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 123); break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 129); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 113); break;
                    case TokenType::STRINGLIT:
                        shift(p, lasttok, lookahead, stack, steps, 127); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 128); break;
                    case TokenType::TILDE:
                        shift(p, lasttok, lookahead, stack, steps, 109); break;
                    case TokenType::TRUELIT:
                        shift(p, lasttok, lookahead, stack, steps, 118); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "binary and expression", "binary or expression")  });
                }
                break;
            case 154:
                switch (lookahead.type) {
                    case TokenType::NEWLINE:
                        shift(p, lasttok, lookahead, stack, steps, 199); break;
                    case TokenType::OCURB:
                        shift(p, lasttok, lookahead, stack, steps, 76); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "code block", "if expression")  });
                }
                break;
            case 155:
                switch (lookahead.type) {
                    case TokenType::NEWLINE:
                        shift(p, lasttok, lookahead, stack, steps, 199); break;
                    case TokenType::OCURB:
                        shift(p, lasttok, lookahead, stack, steps, 76); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "code block", "while loop expression")  });
                }
                break;
            case 156:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                        shift(p, lasttok, lookahead, stack, steps, 112); break;
                    case TokenType::BANG:
                        shift(p, lasttok, lookahead, stack, steps, 111); break;
                    case TokenType::BININTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 124); break;
                    case TokenType::CHARLIT:
                        shift(p, lasttok, lookahead, stack, steps, 126); break;
                    case TokenType::DECINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 122); break;
                    case TokenType::FALSELIT:
                        shift(p, lasttok, lookahead, stack, steps, 119); break;
                    case TokenType::FLOATLIT:
                        shift(p, lasttok, lookahead, stack, steps, 120); break;
                    case TokenType::HEXINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 125); break;
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 110); break;
                    case TokenType::NULLPTRLIT:
                        shift(p, lasttok, lookahead, stack, steps, 121); break;
                    case TokenType::OCTINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 123); break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 129); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 113); break;
                    case TokenType::STRINGLIT:
                        shift(p, lasttok, lookahead, stack, steps, 127); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 128); break;
                    case TokenType::TILDE:
                        shift(p, lasttok, lookahead, stack, steps, 109); break;
                    case TokenType::TRUELIT:
                        shift(p, lasttok, lookahead, stack, steps, 118); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "equality expression", "binary and expression")  });
                }
                break;
            case 157:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                        shift(p, lasttok, lookahead, stack, steps, 112); break;
                    case TokenType::BANG:
                        shift(p, lasttok, lookahead, stack, steps, 111); break;
                    case TokenType::BININTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 124); break;
                    case TokenType::CHARLIT:
                        shift(p, lasttok, lookahead, stack, steps, 126); break;
                    case TokenType::DECINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 122); break;
                    case TokenType::FALSELIT:
                        shift(p, lasttok, lookahead, stack, steps, 119); break;
                    case TokenType::FLOATLIT:
                        shift(p, lasttok, lookahead, stack, steps, 120); break;
                    case TokenType::HEXINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 125); break;
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 110); break;
                    case TokenType::NULLPTRLIT:
                        shift(p, lasttok, lookahead, stack, steps, 121); break;
                    case TokenType::OCTINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 123); break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 129); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 113); break;
                    case TokenType::STRINGLIT:
                        shift(p, lasttok, lookahead, stack, steps, 127); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 128); break;
                    case TokenType::TILDE:
                        shift(p, lasttok, lookahead, stack, steps, 109); break;
                    case TokenType::TRUELIT:
                        shift(p, lasttok, lookahead, stack, steps, 118); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "comparison expression", "equality expression")  });
                }
                break;
            case 158:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                        shift(p, lasttok, lookahead, stack, steps, 112); break;
                    case TokenType::BANG:
                        shift(p, lasttok, lookahead, stack, steps, 111); break;
                    case TokenType::BININTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 124); break;
                    case TokenType::CHARLIT:
                        shift(p, lasttok, lookahead, stack, steps, 126); break;
                    case TokenType::DECINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 122); break;
                    case TokenType::FALSELIT:
                        shift(p, lasttok, lookahead, stack, steps, 119); break;
                    case TokenType::FLOATLIT:
                        shift(p, lasttok, lookahead, stack, steps, 120); break;
                    case TokenType::HEXINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 125); break;
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 110); break;
                    case TokenType::NULLPTRLIT:
                        shift(p, lasttok, lookahead, stack, steps, 121); break;
                    case TokenType::OCTINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 123); break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 129); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 113); break;
                    case TokenType::STRINGLIT:
                        shift(p, lasttok, lookahead, stack, steps, 127); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 128); break;
                    case TokenType::TILDE:
                        shift(p, lasttok, lookahead, stack, steps, 109); break;
                    case TokenType::TRUELIT:
                        shift(p, lasttok, lookahead, stack, steps, 118); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "comparison expression", "equality expression")  });
                }
                break;
            case 159:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                        shift(p, lasttok, lookahead, stack, steps, 112); break;
                    case TokenType::BANG:
                        shift(p, lasttok, lookahead, stack, steps, 111); break;
                    case TokenType::BININTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 124); break;
                    case TokenType::CHARLIT:
                        shift(p, lasttok, lookahead, stack, steps, 126); break;
                    case TokenType::DECINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 122); break;
                    case TokenType::FALSELIT:
                        shift(p, lasttok, lookahead, stack, steps, 119); break;
                    case TokenType::FLOATLIT:
                        shift(p, lasttok, lookahead, stack, steps, 120); break;
                    case TokenType::HEXINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 125); break;
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 110); break;
                    case TokenType::NULLPTRLIT:
                        shift(p, lasttok, lookahead, stack, steps, 121); break;
                    case TokenType::OCTINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 123); break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 129); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 113); break;
                    case TokenType::STRINGLIT:
                        shift(p, lasttok, lookahead, stack, steps, 127); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 128); break;
                    case TokenType::TILDE:
                        shift(p, lasttok, lookahead, stack, steps, 109); break;
                    case TokenType::TRUELIT:
                        shift(p, lasttok, lookahead, stack, steps, 118); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "bitwise xor expression", "comparison expression")  });
                }
                break;
            case 160:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                        shift(p, lasttok, lookahead, stack, steps, 112); break;
                    case TokenType::BANG:
                        shift(p, lasttok, lookahead, stack, steps, 111); break;
                    case TokenType::BININTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 124); break;
                    case TokenType::CHARLIT:
                        shift(p, lasttok, lookahead, stack, steps, 126); break;
                    case TokenType::DECINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 122); break;
                    case TokenType::FALSELIT:
                        shift(p, lasttok, lookahead, stack, steps, 119); break;
                    case TokenType::FLOATLIT:
                        shift(p, lasttok, lookahead, stack, steps, 120); break;
                    case TokenType::HEXINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 125); break;
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 110); break;
                    case TokenType::NULLPTRLIT:
                        shift(p, lasttok, lookahead, stack, steps, 121); break;
                    case TokenType::OCTINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 123); break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 129); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 113); break;
                    case TokenType::STRINGLIT:
                        shift(p, lasttok, lookahead, stack, steps, 127); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 128); break;
                    case TokenType::TILDE:
                        shift(p, lasttok, lookahead, stack, steps, 109); break;
                    case TokenType::TRUELIT:
                        shift(p, lasttok, lookahead, stack, steps, 118); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "bitwise xor expression", "comparison expression")  });
                }
                break;
            case 161:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                        shift(p, lasttok, lookahead, stack, steps, 112); break;
                    case TokenType::BANG:
                        shift(p, lasttok, lookahead, stack, steps, 111); break;
                    case TokenType::BININTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 124); break;
                    case TokenType::CHARLIT:
                        shift(p, lasttok, lookahead, stack, steps, 126); break;
                    case TokenType::DECINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 122); break;
                    case TokenType::FALSELIT:
                        shift(p, lasttok, lookahead, stack, steps, 119); break;
                    case TokenType::FLOATLIT:
                        shift(p, lasttok, lookahead, stack, steps, 120); break;
                    case TokenType::HEXINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 125); break;
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 110); break;
                    case TokenType::NULLPTRLIT:
                        shift(p, lasttok, lookahead, stack, steps, 121); break;
                    case TokenType::OCTINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 123); break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 129); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 113); break;
                    case TokenType::STRINGLIT:
                        shift(p, lasttok, lookahead, stack, steps, 127); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 128); break;
                    case TokenType::TILDE:
                        shift(p, lasttok, lookahead, stack, steps, 109); break;
                    case TokenType::TRUELIT:
                        shift(p, lasttok, lookahead, stack, steps, 118); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "bitwise xor expression", "comparison expression")  });
                }
                break;
            case 162:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                        shift(p, lasttok, lookahead, stack, steps, 112); break;
                    case TokenType::BANG:
                        shift(p, lasttok, lookahead, stack, steps, 111); break;
                    case TokenType::BININTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 124); break;
                    case TokenType::CHARLIT:
                        shift(p, lasttok, lookahead, stack, steps, 126); break;
                    case TokenType::DECINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 122); break;
                    case TokenType::FALSELIT:
                        shift(p, lasttok, lookahead, stack, steps, 119); break;
                    case TokenType::FLOATLIT:
                        shift(p, lasttok, lookahead, stack, steps, 120); break;
                    case TokenType::HEXINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 125); break;
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 110); break;
                    case TokenType::NULLPTRLIT:
                        shift(p, lasttok, lookahead, stack, steps, 121); break;
                    case TokenType::OCTINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 123); break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 129); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 113); break;
                    case TokenType::STRINGLIT:
                        shift(p, lasttok, lookahead, stack, steps, 127); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 128); break;
                    case TokenType::TILDE:
                        shift(p, lasttok, lookahead, stack, steps, 109); break;
                    case TokenType::TRUELIT:
                        shift(p, lasttok, lookahead, stack, steps, 118); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "bitwise xor expression", "comparison expression")  });
                }
                break;
            case 163:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                        shift(p, lasttok, lookahead, stack, steps, 112); break;
                    case TokenType::BANG:
                        shift(p, lasttok, lookahead, stack, steps, 111); break;
                    case TokenType::BININTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 124); break;
                    case TokenType::CHARLIT:
                        shift(p, lasttok, lookahead, stack, steps, 126); break;
                    case TokenType::DECINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 122); break;
                    case TokenType::FALSELIT:
                        shift(p, lasttok, lookahead, stack, steps, 119); break;
                    case TokenType::FLOATLIT:
                        shift(p, lasttok, lookahead, stack, steps, 120); break;
                    case TokenType::HEXINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 125); break;
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 110); break;
                    case TokenType::NULLPTRLIT:
                        shift(p, lasttok, lookahead, stack, steps, 121); break;
                    case TokenType::OCTINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 123); break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 129); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 113); break;
                    case TokenType::STRINGLIT:
                        shift(p, lasttok, lookahead, stack, steps, 127); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 128); break;
                    case TokenType::TILDE:
                        shift(p, lasttok, lookahead, stack, steps, 109); break;
                    case TokenType::TRUELIT:
                        shift(p, lasttok, lookahead, stack, steps, 118); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "bitwise or expression", "bitwise xor expression")  });
                }
                break;
            case 164:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                        shift(p, lasttok, lookahead, stack, steps, 112); break;
                    case TokenType::BANG:
                        shift(p, lasttok, lookahead, stack, steps, 111); break;
                    case TokenType::BININTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 124); break;
                    case TokenType::CHARLIT:
                        shift(p, lasttok, lookahead, stack, steps, 126); break;
                    case TokenType::DECINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 122); break;
                    case TokenType::FALSELIT:
                        shift(p, lasttok, lookahead, stack, steps, 119); break;
                    case TokenType::FLOATLIT:
                        shift(p, lasttok, lookahead, stack, steps, 120); break;
                    case TokenType::HEXINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 125); break;
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 110); break;
                    case TokenType::NULLPTRLIT:
                        shift(p, lasttok, lookahead, stack, steps, 121); break;
                    case TokenType::OCTINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 123); break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 129); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 113); break;
                    case TokenType::STRINGLIT:
                        shift(p, lasttok, lookahead, stack, steps, 127); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 128); break;
                    case TokenType::TILDE:
                        shift(p, lasttok, lookahead, stack, steps, 109); break;
                    case TokenType::TRUELIT:
                        shift(p, lasttok, lookahead, stack, steps, 118); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "bitwise and expression", "bitwise or expression")  });
                }
                break;
            case 165:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                        shift(p, lasttok, lookahead, stack, steps, 112); break;
                    case TokenType::BANG:
                        shift(p, lasttok, lookahead, stack, steps, 111); break;
                    case TokenType::BININTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 124); break;
                    case TokenType::CHARLIT:
                        shift(p, lasttok, lookahead, stack, steps, 126); break;
                    case TokenType::DECINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 122); break;
                    case TokenType::FALSELIT:
                        shift(p, lasttok, lookahead, stack, steps, 119); break;
                    case TokenType::FLOATLIT:
                        shift(p, lasttok, lookahead, stack, steps, 120); break;
                    case TokenType::HEXINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 125); break;
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 110); break;
                    case TokenType::NULLPTRLIT:
                        shift(p, lasttok, lookahead, stack, steps, 121); break;
                    case TokenType::OCTINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 123); break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 129); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 113); break;
                    case TokenType::STRINGLIT:
                        shift(p, lasttok, lookahead, stack, steps, 127); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 128); break;
                    case TokenType::TILDE:
                        shift(p, lasttok, lookahead, stack, steps, 109); break;
                    case TokenType::TRUELIT:
                        shift(p, lasttok, lookahead, stack, steps, 118); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "bit shift expression", "bitwise and expression")  });
                }
                break;
            case 166:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                        shift(p, lasttok, lookahead, stack, steps, 112); break;
                    case TokenType::BANG:
                        shift(p, lasttok, lookahead, stack, steps, 111); break;
                    case TokenType::BININTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 124); break;
                    case TokenType::CHARLIT:
                        shift(p, lasttok, lookahead, stack, steps, 126); break;
                    case TokenType::DECINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 122); break;
                    case TokenType::FALSELIT:
                        shift(p, lasttok, lookahead, stack, steps, 119); break;
                    case TokenType::FLOATLIT:
                        shift(p, lasttok, lookahead, stack, steps, 120); break;
                    case TokenType::HEXINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 125); break;
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 110); break;
                    case TokenType::NULLPTRLIT:
                        shift(p, lasttok, lookahead, stack, steps, 121); break;
                    case TokenType::OCTINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 123); break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 129); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 113); break;
                    case TokenType::STRINGLIT:
                        shift(p, lasttok, lookahead, stack, steps, 127); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 128); break;
                    case TokenType::TILDE:
                        shift(p, lasttok, lookahead, stack, steps, 109); break;
                    case TokenType::TRUELIT:
                        shift(p, lasttok, lookahead, stack, steps, 118); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "addition expression", "bit shift expression")  });
                }
                break;
            case 167:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                        shift(p, lasttok, lookahead, stack, steps, 112); break;
                    case TokenType::BANG:
                        shift(p, lasttok, lookahead, stack, steps, 111); break;
                    case TokenType::BININTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 124); break;
                    case TokenType::CHARLIT:
                        shift(p, lasttok, lookahead, stack, steps, 126); break;
                    case TokenType::DECINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 122); break;
                    case TokenType::FALSELIT:
                        shift(p, lasttok, lookahead, stack, steps, 119); break;
                    case TokenType::FLOATLIT:
                        shift(p, lasttok, lookahead, stack, steps, 120); break;
                    case TokenType::HEXINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 125); break;
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 110); break;
                    case TokenType::NULLPTRLIT:
                        shift(p, lasttok, lookahead, stack, steps, 121); break;
                    case TokenType::OCTINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 123); break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 129); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 113); break;
                    case TokenType::STRINGLIT:
                        shift(p, lasttok, lookahead, stack, steps, 127); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 128); break;
                    case TokenType::TILDE:
                        shift(p, lasttok, lookahead, stack, steps, 109); break;
                    case TokenType::TRUELIT:
                        shift(p, lasttok, lookahead, stack, steps, 118); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "addition expression", "bit shift expression")  });
                }
                break;
            case 168:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                        shift(p, lasttok, lookahead, stack, steps, 112); break;
                    case TokenType::BANG:
                        shift(p, lasttok, lookahead, stack, steps, 111); break;
                    case TokenType::BININTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 124); break;
                    case TokenType::CHARLIT:
                        shift(p, lasttok, lookahead, stack, steps, 126); break;
                    case TokenType::DECINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 122); break;
                    case TokenType::FALSELIT:
                        shift(p, lasttok, lookahead, stack, steps, 119); break;
                    case TokenType::FLOATLIT:
                        shift(p, lasttok, lookahead, stack, steps, 120); break;
                    case TokenType::HEXINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 125); break;
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 110); break;
                    case TokenType::NULLPTRLIT:
                        shift(p, lasttok, lookahead, stack, steps, 121); break;
                    case TokenType::OCTINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 123); break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 129); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 113); break;
                    case TokenType::STRINGLIT:
                        shift(p, lasttok, lookahead, stack, steps, 127); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 128); break;
                    case TokenType::TILDE:
                        shift(p, lasttok, lookahead, stack, steps, 109); break;
                    case TokenType::TRUELIT:
                        shift(p, lasttok, lookahead, stack, steps, 118); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "multiplication expression", "addition expression")  });
                }
                break;
            case 169:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                        shift(p, lasttok, lookahead, stack, steps, 112); break;
                    case TokenType::BANG:
                        shift(p, lasttok, lookahead, stack, steps, 111); break;
                    case TokenType::BININTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 124); break;
                    case TokenType::CHARLIT:
                        shift(p, lasttok, lookahead, stack, steps, 126); break;
                    case TokenType::DECINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 122); break;
                    case TokenType::FALSELIT:
                        shift(p, lasttok, lookahead, stack, steps, 119); break;
                    case TokenType::FLOATLIT:
                        shift(p, lasttok, lookahead, stack, steps, 120); break;
                    case TokenType::HEXINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 125); break;
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 110); break;
                    case TokenType::NULLPTRLIT:
                        shift(p, lasttok, lookahead, stack, steps, 121); break;
                    case TokenType::OCTINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 123); break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 129); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 113); break;
                    case TokenType::STRINGLIT:
                        shift(p, lasttok, lookahead, stack, steps, 127); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 128); break;
                    case TokenType::TILDE:
                        shift(p, lasttok, lookahead, stack, steps, 109); break;
                    case TokenType::TRUELIT:
                        shift(p, lasttok, lookahead, stack, steps, 118); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "multiplication expression", "addition expression")  });
                }
                break;
            case 170:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                        shift(p, lasttok, lookahead, stack, steps, 112); break;
                    case TokenType::BANG:
                        shift(p, lasttok, lookahead, stack, steps, 111); break;
                    case TokenType::BININTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 124); break;
                    case TokenType::CHARLIT:
                        shift(p, lasttok, lookahead, stack, steps, 126); break;
                    case TokenType::DECINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 122); break;
                    case TokenType::FALSELIT:
                        shift(p, lasttok, lookahead, stack, steps, 119); break;
                    case TokenType::FLOATLIT:
                        shift(p, lasttok, lookahead, stack, steps, 120); break;
                    case TokenType::HEXINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 125); break;
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 110); break;
                    case TokenType::NULLPTRLIT:
                        shift(p, lasttok, lookahead, stack, steps, 121); break;
                    case TokenType::OCTINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 123); break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 129); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 113); break;
                    case TokenType::STRINGLIT:
                        shift(p, lasttok, lookahead, stack, steps, 127); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 128); break;
                    case TokenType::TILDE:
                        shift(p, lasttok, lookahead, stack, steps, 109); break;
                    case TokenType::TRUELIT:
                        shift(p, lasttok, lookahead, stack, steps, 118); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "unary expression", "multiplication expression")  });
                }
                break;
            case 171:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                        shift(p, lasttok, lookahead, stack, steps, 112); break;
                    case TokenType::BANG:
                        shift(p, lasttok, lookahead, stack, steps, 111); break;
                    case TokenType::BININTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 124); break;
                    case TokenType::CHARLIT:
                        shift(p, lasttok, lookahead, stack, steps, 126); break;
                    case TokenType::DECINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 122); break;
                    case TokenType::FALSELIT:
                        shift(p, lasttok, lookahead, stack, steps, 119); break;
                    case TokenType::FLOATLIT:
                        shift(p, lasttok, lookahead, stack, steps, 120); break;
                    case TokenType::HEXINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 125); break;
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 110); break;
                    case TokenType::NULLPTRLIT:
                        shift(p, lasttok, lookahead, stack, steps, 121); break;
                    case TokenType::OCTINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 123); break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 129); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 113); break;
                    case TokenType::STRINGLIT:
                        shift(p, lasttok, lookahead, stack, steps, 127); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 128); break;
                    case TokenType::TILDE:
                        shift(p, lasttok, lookahead, stack, steps, 109); break;
                    case TokenType::TRUELIT:
                        shift(p, lasttok, lookahead, stack, steps, 118); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "unary expression", "multiplication expression")  });
                }
                break;
            case 172:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                        shift(p, lasttok, lookahead, stack, steps, 112); break;
                    case TokenType::BANG:
                        shift(p, lasttok, lookahead, stack, steps, 111); break;
                    case TokenType::BININTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 124); break;
                    case TokenType::CHARLIT:
                        shift(p, lasttok, lookahead, stack, steps, 126); break;
                    case TokenType::DECINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 122); break;
                    case TokenType::FALSELIT:
                        shift(p, lasttok, lookahead, stack, steps, 119); break;
                    case TokenType::FLOATLIT:
                        shift(p, lasttok, lookahead, stack, steps, 120); break;
                    case TokenType::HEXINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 125); break;
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 110); break;
                    case TokenType::NULLPTRLIT:
                        shift(p, lasttok, lookahead, stack, steps, 121); break;
                    case TokenType::OCTINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 123); break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 129); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 113); break;
                    case TokenType::STRINGLIT:
                        shift(p, lasttok, lookahead, stack, steps, 127); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 128); break;
                    case TokenType::TILDE:
                        shift(p, lasttok, lookahead, stack, steps, 109); break;
                    case TokenType::TRUELIT:
                        shift(p, lasttok, lookahead, stack, steps, 118); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "unary expression", "multiplication expression")  });
                }
                break;
            case 173:
                switch (lookahead.type) {
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 16); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 17); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "type specifier", "type cast expression")  });
                }
                break;
            case 174:
                switch (lookahead.type) {
                    default: {
                            auto a1 (pop_a<ASTNS::Expr>(stack));
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                a1 ? Maybe(a1->end()) :
                                Maybe<Location const>(a0);
std::unique_ptr<ASTNS::UnaryExpr> push (std::make_unique<ASTNS::UnaryExpr>(p.sourcefile, start, end, a0, std::move(a1)));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_41, stack.back().state), std::move(pushitem), NonTerminal::_41);
                        }
                        break;
                }
                break;
            case 175:
                switch (lookahead.type) {
                    default: {
                            auto a1 (pop_a<ASTNS::Expr>(stack));
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                a1 ? Maybe(a1->end()) :
                                Maybe<Location const>(a0);
std::unique_ptr<ASTNS::UnaryExpr> push (std::make_unique<ASTNS::UnaryExpr>(p.sourcefile, start, end, a0, std::move(a1)));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_41, stack.back().state), std::move(pushitem), NonTerminal::_41);
                        }
                        break;
                }
                break;
            case 176:
                switch (lookahead.type) {
                    default: {
                            auto a1 (pop_a<ASTNS::Expr>(stack));
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                a1 ? Maybe(a1->end()) :
                                Maybe<Location const>(a0);
std::unique_ptr<ASTNS::UnaryExpr> push (std::make_unique<ASTNS::UnaryExpr>(p.sourcefile, start, end, a0, std::move(a1)));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_41, stack.back().state), std::move(pushitem), NonTerminal::_41);
                        }
                        break;
                }
                break;
            case 177:
                switch (lookahead.type) {
                    default: {
                            auto a1 (pop_a<ASTNS::Expr>(stack));
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                a1 ? Maybe(a1->end()) :
                                Maybe<Location const>(a0);
std::unique_ptr<ASTNS::AddrofExpr> push (std::make_unique<ASTNS::AddrofExpr>(p.sourcefile, start, end, a0, std::move(a1), false));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_41, stack.back().state), std::move(pushitem), NonTerminal::_41);
                        }
                        break;
                }
                break;
            case 178:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                        shift(p, lasttok, lookahead, stack, steps, 112); break;
                    case TokenType::BANG:
                        shift(p, lasttok, lookahead, stack, steps, 111); break;
                    case TokenType::BININTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 124); break;
                    case TokenType::CHARLIT:
                        shift(p, lasttok, lookahead, stack, steps, 126); break;
                    case TokenType::DECINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 122); break;
                    case TokenType::FALSELIT:
                        shift(p, lasttok, lookahead, stack, steps, 119); break;
                    case TokenType::FLOATLIT:
                        shift(p, lasttok, lookahead, stack, steps, 120); break;
                    case TokenType::HEXINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 125); break;
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 110); break;
                    case TokenType::NULLPTRLIT:
                        shift(p, lasttok, lookahead, stack, steps, 121); break;
                    case TokenType::OCTINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 123); break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 129); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 113); break;
                    case TokenType::STRINGLIT:
                        shift(p, lasttok, lookahead, stack, steps, 127); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 128); break;
                    case TokenType::TILDE:
                        shift(p, lasttok, lookahead, stack, steps, 109); break;
                    case TokenType::TRUELIT:
                        shift(p, lasttok, lookahead, stack, steps, 118); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "unary expression", "unary expression")  });
                }
                break;
            case 179:
                switch (lookahead.type) {
                    default: {
                            auto a1 (pop_a<ASTNS::Expr>(stack));
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                a1 ? Maybe(a1->end()) :
                                Maybe<Location const>(a0);
std::unique_ptr<ASTNS::DerefExpr> push (std::make_unique<ASTNS::DerefExpr>(p.sourcefile, start, end, a0, std::move(a1)));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_41, stack.back().state), std::move(pushitem), NonTerminal::_41);
                        }
                        break;
                }
                break;
            case 180:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                        shift(p, lasttok, lookahead, stack, steps, 112); break;
                    case TokenType::BANG:
                        shift(p, lasttok, lookahead, stack, steps, 111); break;
                    case TokenType::BININTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 124); break;
                    case TokenType::CHARLIT:
                        shift(p, lasttok, lookahead, stack, steps, 126); break;
                    case TokenType::CPARN:
{
std::unique_ptr<ASTNS::ArgList> push (std::make_unique<ASTNS::ArgList>(p.sourcefile, Maybe<Location const>(), Maybe<Location const>(), std::vector<std::unique_ptr<ASTNS::Arg>> {}));
                            std::unique_ptr<ASTNS::ArgList> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_65, stack.back().state), std::move(pushitem), NonTerminal::_65);
                        }
                        break;
                    case TokenType::DECINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 122); break;
                    case TokenType::FALSELIT:
                        shift(p, lasttok, lookahead, stack, steps, 119); break;
                    case TokenType::FLOATLIT:
                        shift(p, lasttok, lookahead, stack, steps, 120); break;
                    case TokenType::HEXINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 125); break;
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::IF:
                        shift(p, lasttok, lookahead, stack, steps, 96); break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 110); break;
                    case TokenType::NULLPTRLIT:
                        shift(p, lasttok, lookahead, stack, steps, 121); break;
                    case TokenType::OCTINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 123); break;
                    case TokenType::OCURB:
                        shift(p, lasttok, lookahead, stack, steps, 76); break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 129); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 113); break;
                    case TokenType::STRINGLIT:
                        shift(p, lasttok, lookahead, stack, steps, 127); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 128); break;
                    case TokenType::TILDE:
                        shift(p, lasttok, lookahead, stack, steps, 109); break;
                    case TokenType::TRUELIT:
                        shift(p, lasttok, lookahead, stack, steps, 118); break;
                    case TokenType::WHILE:
                        shift(p, lasttok, lookahead, stack, steps, 97); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "optional argument list", "function call expression")  });
                }
                break;
            case 181:
                switch (lookahead.type) {
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 225); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", stringify_token_type(TokenType::IDENTIFIER), "field access expression"), format("expected {} for {}", stringify_token_type(TokenType::IDENTIFIER), "method call expression")  });
                }
                break;
            case 182:
                switch (lookahead.type) {
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 226); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", stringify_token_type(TokenType::IDENTIFIER), "field access expression"), format("expected {} for {}", stringify_token_type(TokenType::IDENTIFIER), "method call expression")  });
                }
                break;
            case 183:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                        shift(p, lasttok, lookahead, stack, steps, 112); break;
                    case TokenType::BANG:
                        shift(p, lasttok, lookahead, stack, steps, 111); break;
                    case TokenType::BININTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 124); break;
                    case TokenType::CHARLIT:
                        shift(p, lasttok, lookahead, stack, steps, 126); break;
                    case TokenType::CPARN:
{
std::unique_ptr<ASTNS::ArgList> push (std::make_unique<ASTNS::ArgList>(p.sourcefile, Maybe<Location const>(), Maybe<Location const>(), std::vector<std::unique_ptr<ASTNS::Arg>> {}));
                            std::unique_ptr<ASTNS::ArgList> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_65, stack.back().state), std::move(pushitem), NonTerminal::_65);
                        }
                        break;
                    case TokenType::DECINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 122); break;
                    case TokenType::FALSELIT:
                        shift(p, lasttok, lookahead, stack, steps, 119); break;
                    case TokenType::FLOATLIT:
                        shift(p, lasttok, lookahead, stack, steps, 120); break;
                    case TokenType::HEXINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 125); break;
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::IF:
                        shift(p, lasttok, lookahead, stack, steps, 96); break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 110); break;
                    case TokenType::NULLPTRLIT:
                        shift(p, lasttok, lookahead, stack, steps, 121); break;
                    case TokenType::OCTINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 123); break;
                    case TokenType::OCURB:
                        shift(p, lasttok, lookahead, stack, steps, 76); break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 129); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 113); break;
                    case TokenType::STRINGLIT:
                        shift(p, lasttok, lookahead, stack, steps, 127); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 128); break;
                    case TokenType::TILDE:
                        shift(p, lasttok, lookahead, stack, steps, 109); break;
                    case TokenType::TRUELIT:
                        shift(p, lasttok, lookahead, stack, steps, 118); break;
                    case TokenType::WHILE:
                        shift(p, lasttok, lookahead, stack, steps, 97); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "optional argument list", "function call expression")  });
                }
                break;
            case 184:
                switch (lookahead.type) {
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 228); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", stringify_token_type(TokenType::IDENTIFIER), "field access expression"), format("expected {} for {}", stringify_token_type(TokenType::IDENTIFIER), "method call expression")  });
                }
                break;
            case 185:
                switch (lookahead.type) {
                    case TokenType::CPARN:
                        shift(p, lasttok, lookahead, stack, steps, 229); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", stringify_token_type(TokenType::CPARN), "primary expression")  });
                }
                break;
            case 186:
                switch (lookahead.type) {
                    default: {
                            auto a3 (pop_t(stack));
                            auto a2 (pop_a<ASTNS::StmtList>(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                Maybe<Location const>(a3);
std::unique_ptr<ASTNS::Block> push (std::make_unique<ASTNS::Block>(p.sourcefile, start, end, std::move(a2->stmts)));
                            std::unique_ptr<ASTNS::Block> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_14, stack.back().state), std::move(pushitem), NonTerminal::_14);
                        }
                        break;
                }
                break;
            case 187:
                switch (lookahead.type) {
                    default: {
                            auto a3 (pop_t(stack));
                            auto a2 (pop_a<ASTNS::StmtList>(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                Maybe<Location const>(a3);
WARN_BLOCK_NO_INDENT(a0, a3);std::unique_ptr<ASTNS::Block> push (std::make_unique<ASTNS::Block>(p.sourcefile, start, end, std::move(a2->stmts)));
                            std::unique_ptr<ASTNS::Block> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_13, stack.back().state), std::move(pushitem), NonTerminal::_13);
                        }
                        break;
                }
                break;
            case 188:
                switch (lookahead.type) {
                    case TokenType::DEDENT:
                        shift(p, lasttok, lookahead, stack, steps, 230); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", stringify_token_type(TokenType::DEDENT), "braced code block")  });
                }
                break;
            case 189:
                switch (lookahead.type) {
                    default: {
                            auto a2 (pop_a<ASTNS::PureLocation>(stack));
                            auto a1 (pop_a<ASTNS::VarStmtItemList>(stack));
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                a2 ? Maybe(a2->end()) :
                                a1 ? Maybe(a1->end()) :
                                Maybe<Location const>(a0);
std::unique_ptr<ASTNS::VarStmt> push (std::make_unique<ASTNS::VarStmt>(p.sourcefile, start, end, std::move(a1->items)));
                            std::unique_ptr<ASTNS::VarStmt> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_7, stack.back().state), std::move(pushitem), NonTerminal::_7);
                        }
                        break;
                }
                break;
            case 190:
                switch (lookahead.type) {
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 142); break;
                    case TokenType::MUT:
                        shift(p, lasttok, lookahead, stack, steps, 143); break;
                    default: {
                            auto a1 (pop_t(stack));
                            auto a0 (pop_a<ASTNS::VarStmtItemList>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) :
                                Maybe<Location const>(a1);
                            Maybe<Location const> end =
                                Maybe<Location const>(a1);
                            std::unique_ptr<ASTNS::VarStmtItemList> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_56, stack.back().state), std::move(pushitem), NonTerminal::_56);
                        }
                        break;
                }
                break;
            case 191:
                switch (lookahead.type) {
                    default: {
                            auto a1 (pop_a<ASTNS::Type>(stack));
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                a1 ? Maybe(a1->end()) :
                                Maybe<Location const>(a0);
std::unique_ptr<ASTNS::VarStmtItem> push (std::make_unique<ASTNS::VarStmtItem>(p.sourcefile, start, end, std::move(a1), false, a0, a0, nullptr));
                            std::unique_ptr<ASTNS::VarStmtItem> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_10, stack.back().state), std::move(pushitem), NonTerminal::_10);
                        }
                        break;
                    case TokenType::EQUAL:
                        shift(p, lasttok, lookahead, stack, steps, 233); break;
                }
                break;
            case 192:
                switch (lookahead.type) {
                    case TokenType::COLON:
                        shift(p, lasttok, lookahead, stack, steps, 51); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "required type annotation", "variable binding")  });
                }
                break;
            case 193:
                switch (lookahead.type) {
                    default: {
                            auto a2 (pop_a<ASTNS::PureLocation>(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) :
                                Maybe<Location const>(a1);
                            Maybe<Location const> end =
                                a2 ? Maybe(a2->end()) :
                                Maybe<Location const>(a1);
std::unique_ptr<ASTNS::ExprStmt> push (std::make_unique<ASTNS::ExprStmt>(p.sourcefile, start, end, std::move(a0), true , Maybe<Location const>(a1)));
                            std::unique_ptr<ASTNS::ExprStmt> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_8, stack.back().state), std::move(pushitem), NonTerminal::_8);
                        }
                        break;
                }
                break;
            case 194:
                switch (lookahead.type) {
                    default: {
                            auto a2 (pop_a<ASTNS::PureLocation>(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) :
                                Maybe<Location const>(a1);
                            Maybe<Location const> end =
                                a2 ? Maybe(a2->end()) :
                                Maybe<Location const>(a1);
std::unique_ptr<ASTNS::ExprStmt> push (std::make_unique<ASTNS::ExprStmt>(p.sourcefile, start, end, std::move(a0), true , Maybe<Location const>(a1)));
                            std::unique_ptr<ASTNS::ExprStmt> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_8, stack.back().state), std::move(pushitem), NonTerminal::_8);
                        }
                        break;
                }
                break;
            case 195:
                switch (lookahead.type) {
                    default: {
                            auto a2 (pop_a<ASTNS::PureLocation>(stack));
                            auto a1 (pop_a<ASTNS::Expr>(stack));
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                a2 ? Maybe(a2->end()) :
                                a1 ? Maybe(a1->end()) :
                                Maybe<Location const>(a0);
std::unique_ptr<ASTNS::RetStmt> push (std::make_unique<ASTNS::RetStmt>(p.sourcefile, start, end, std::move(a1)));
                            std::unique_ptr<ASTNS::RetStmt> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_9, stack.back().state), std::move(pushitem), NonTerminal::_9);
                        }
                        break;
                }
                break;
            case 196:
                switch (lookahead.type) {
                    default: {
                            auto a2 (pop_a<ASTNS::Expr>(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) :
                                Maybe<Location const>(a1);
                            Maybe<Location const> end =
                                a2 ? Maybe(a2->end()) :
                                Maybe<Location const>(a1);
std::unique_ptr<ASTNS::AssignmentExpr> push (std::make_unique<ASTNS::AssignmentExpr>(p.sourcefile, start, end, std::move(a0), a1, std::move(a2)));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_29, stack.back().state), std::move(pushitem), NonTerminal::_29);
                        }
                        break;
                }
                break;
            case 197:
                switch (lookahead.type) {
                    default: {
                            auto a2 (pop_a<ASTNS::Expr>(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) :
                                Maybe<Location const>(a1);
                            Maybe<Location const> end =
                                a2 ? Maybe(a2->end()) :
                                Maybe<Location const>(a1);
std::unique_ptr<ASTNS::ShortCircuitExpr> push (std::make_unique<ASTNS::ShortCircuitExpr>(p.sourcefile, start, end, std::move(a0), a1, std::move(a2)));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_30, stack.back().state), std::move(pushitem), NonTerminal::_30);
                        }
                        break;
                    case TokenType::DOUBLEAMPER:
                        shift(p, lasttok, lookahead, stack, steps, 156); break;
                }
                break;
            case 198:
                switch (lookahead.type) {
                    default: {
                            auto a2 (pop_a<ASTNS::Block>(stack));
                            auto a1 (pop_a<ASTNS::Expr>(stack));
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                a2 ? Maybe(a2->end()) :
                                a1 ? Maybe(a1->end()) :
                                Maybe<Location const>(a0);
std::unique_ptr<ASTNS::IfExpr> push (std::make_unique<ASTNS::IfExpr>(p.sourcefile, start, end, a0, a0, std::move(a1), std::move(a2), nullptr));
                            std::unique_ptr<ASTNS::IfExpr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_27, stack.back().state), std::move(pushitem), NonTerminal::_27);
                        }
                        break;
                    case TokenType::ELSE:
                        shift(p, lasttok, lookahead, stack, steps, 235); break;
                }
                break;
            case 199:
                switch (lookahead.type) {
                    case TokenType::INDENT:
                        shift(p, lasttok, lookahead, stack, steps, 79); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", stringify_token_type(TokenType::INDENT), "indented code block")  });
                }
                break;
            case 200:
                switch (lookahead.type) {
                    default: {
                            auto a2 (pop_a<ASTNS::Block>(stack));
                            auto a1 (pop_a<ASTNS::Expr>(stack));
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                a2 ? Maybe(a2->end()) :
                                a1 ? Maybe(a1->end()) :
                                Maybe<Location const>(a0);
std::unique_ptr<ASTNS::WhileExpr> push (std::make_unique<ASTNS::WhileExpr>(p.sourcefile, start, end, std::move(a1), std::move(a2)));
                            std::unique_ptr<ASTNS::WhileExpr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_28, stack.back().state), std::move(pushitem), NonTerminal::_28);
                        }
                        break;
                }
                break;
            case 201:
                switch (lookahead.type) {
                    case TokenType::BANGEQUAL:
                        shift(p, lasttok, lookahead, stack, steps, 157); break;
                    default: {
                            auto a2 (pop_a<ASTNS::Expr>(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) :
                                Maybe<Location const>(a1);
                            Maybe<Location const> end =
                                a2 ? Maybe(a2->end()) :
                                Maybe<Location const>(a1);
std::unique_ptr<ASTNS::ShortCircuitExpr> push (std::make_unique<ASTNS::ShortCircuitExpr>(p.sourcefile, start, end, std::move(a0), a1, std::move(a2)));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_31, stack.back().state), std::move(pushitem), NonTerminal::_31);
                        }
                        break;
                    case TokenType::DOUBLEEQUAL:
                        shift(p, lasttok, lookahead, stack, steps, 158); break;
                }
                break;
            case 202:
                switch (lookahead.type) {
                    default: {
                            auto a2 (pop_a<ASTNS::Expr>(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) :
                                Maybe<Location const>(a1);
                            Maybe<Location const> end =
                                a2 ? Maybe(a2->end()) :
                                Maybe<Location const>(a1);
std::unique_ptr<ASTNS::BinaryExpr> push (std::make_unique<ASTNS::BinaryExpr>(p.sourcefile, start, end, std::move(a0), a1, std::move(a2)));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_32, stack.back().state), std::move(pushitem), NonTerminal::_32);
                        }
                        break;
                    case TokenType::GREATER:
                        shift(p, lasttok, lookahead, stack, steps, 160); break;
                    case TokenType::GREATEREQUAL:
                        shift(p, lasttok, lookahead, stack, steps, 162); break;
                    case TokenType::LESS:
                        shift(p, lasttok, lookahead, stack, steps, 159); break;
                    case TokenType::LESSEQUAL:
                        shift(p, lasttok, lookahead, stack, steps, 161); break;
                }
                break;
            case 203:
                switch (lookahead.type) {
                    default: {
                            auto a2 (pop_a<ASTNS::Expr>(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) :
                                Maybe<Location const>(a1);
                            Maybe<Location const> end =
                                a2 ? Maybe(a2->end()) :
                                Maybe<Location const>(a1);
std::unique_ptr<ASTNS::BinaryExpr> push (std::make_unique<ASTNS::BinaryExpr>(p.sourcefile, start, end, std::move(a0), a1, std::move(a2)));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_32, stack.back().state), std::move(pushitem), NonTerminal::_32);
                        }
                        break;
                    case TokenType::GREATER:
                        shift(p, lasttok, lookahead, stack, steps, 160); break;
                    case TokenType::GREATEREQUAL:
                        shift(p, lasttok, lookahead, stack, steps, 162); break;
                    case TokenType::LESS:
                        shift(p, lasttok, lookahead, stack, steps, 159); break;
                    case TokenType::LESSEQUAL:
                        shift(p, lasttok, lookahead, stack, steps, 161); break;
                }
                break;
            case 204:
                switch (lookahead.type) {
                    default: {
                            auto a2 (pop_a<ASTNS::Expr>(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) :
                                Maybe<Location const>(a1);
                            Maybe<Location const> end =
                                a2 ? Maybe(a2->end()) :
                                Maybe<Location const>(a1);
std::unique_ptr<ASTNS::BinaryExpr> push (std::make_unique<ASTNS::BinaryExpr>(p.sourcefile, start, end, std::move(a0), a1, std::move(a2)));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_33, stack.back().state), std::move(pushitem), NonTerminal::_33);
                        }
                        break;
                    case TokenType::CARET:
                        shift(p, lasttok, lookahead, stack, steps, 163); break;
                }
                break;
            case 205:
                switch (lookahead.type) {
                    default: {
                            auto a2 (pop_a<ASTNS::Expr>(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) :
                                Maybe<Location const>(a1);
                            Maybe<Location const> end =
                                a2 ? Maybe(a2->end()) :
                                Maybe<Location const>(a1);
std::unique_ptr<ASTNS::BinaryExpr> push (std::make_unique<ASTNS::BinaryExpr>(p.sourcefile, start, end, std::move(a0), a1, std::move(a2)));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_33, stack.back().state), std::move(pushitem), NonTerminal::_33);
                        }
                        break;
                    case TokenType::CARET:
                        shift(p, lasttok, lookahead, stack, steps, 163); break;
                }
                break;
            case 206:
                switch (lookahead.type) {
                    default: {
                            auto a2 (pop_a<ASTNS::Expr>(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) :
                                Maybe<Location const>(a1);
                            Maybe<Location const> end =
                                a2 ? Maybe(a2->end()) :
                                Maybe<Location const>(a1);
std::unique_ptr<ASTNS::BinaryExpr> push (std::make_unique<ASTNS::BinaryExpr>(p.sourcefile, start, end, std::move(a0), a1, std::move(a2)));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_33, stack.back().state), std::move(pushitem), NonTerminal::_33);
                        }
                        break;
                    case TokenType::CARET:
                        shift(p, lasttok, lookahead, stack, steps, 163); break;
                }
                break;
            case 207:
                switch (lookahead.type) {
                    default: {
                            auto a2 (pop_a<ASTNS::Expr>(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) :
                                Maybe<Location const>(a1);
                            Maybe<Location const> end =
                                a2 ? Maybe(a2->end()) :
                                Maybe<Location const>(a1);
std::unique_ptr<ASTNS::BinaryExpr> push (std::make_unique<ASTNS::BinaryExpr>(p.sourcefile, start, end, std::move(a0), a1, std::move(a2)));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_33, stack.back().state), std::move(pushitem), NonTerminal::_33);
                        }
                        break;
                    case TokenType::CARET:
                        shift(p, lasttok, lookahead, stack, steps, 163); break;
                }
                break;
            case 208:
                switch (lookahead.type) {
                    default: {
                            auto a2 (pop_a<ASTNS::Expr>(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) :
                                Maybe<Location const>(a1);
                            Maybe<Location const> end =
                                a2 ? Maybe(a2->end()) :
                                Maybe<Location const>(a1);
std::unique_ptr<ASTNS::BinaryExpr> push (std::make_unique<ASTNS::BinaryExpr>(p.sourcefile, start, end, std::move(a0), a1, std::move(a2)));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_34, stack.back().state), std::move(pushitem), NonTerminal::_34);
                        }
                        break;
                    case TokenType::PIPE:
                        shift(p, lasttok, lookahead, stack, steps, 164); break;
                }
                break;
            case 209:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                        shift(p, lasttok, lookahead, stack, steps, 165); break;
                    default: {
                            auto a2 (pop_a<ASTNS::Expr>(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) :
                                Maybe<Location const>(a1);
                            Maybe<Location const> end =
                                a2 ? Maybe(a2->end()) :
                                Maybe<Location const>(a1);
std::unique_ptr<ASTNS::BinaryExpr> push (std::make_unique<ASTNS::BinaryExpr>(p.sourcefile, start, end, std::move(a0), a1, std::move(a2)));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_35, stack.back().state), std::move(pushitem), NonTerminal::_35);
                        }
                        break;
                }
                break;
            case 210:
                switch (lookahead.type) {
                    default: {
                            auto a2 (pop_a<ASTNS::Expr>(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) :
                                Maybe<Location const>(a1);
                            Maybe<Location const> end =
                                a2 ? Maybe(a2->end()) :
                                Maybe<Location const>(a1);
std::unique_ptr<ASTNS::BinaryExpr> push (std::make_unique<ASTNS::BinaryExpr>(p.sourcefile, start, end, std::move(a0), a1, std::move(a2)));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_36, stack.back().state), std::move(pushitem), NonTerminal::_36);
                        }
                        break;
                    case TokenType::DOUBLEGREATER:
                        shift(p, lasttok, lookahead, stack, steps, 166); break;
                    case TokenType::DOUBLELESS:
                        shift(p, lasttok, lookahead, stack, steps, 167); break;
                }
                break;
            case 211:
                switch (lookahead.type) {
                    default: {
                            auto a2 (pop_a<ASTNS::Expr>(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) :
                                Maybe<Location const>(a1);
                            Maybe<Location const> end =
                                a2 ? Maybe(a2->end()) :
                                Maybe<Location const>(a1);
std::unique_ptr<ASTNS::BinaryExpr> push (std::make_unique<ASTNS::BinaryExpr>(p.sourcefile, start, end, std::move(a0), a1, std::move(a2)));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_37, stack.back().state), std::move(pushitem), NonTerminal::_37);
                        }
                        break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 169); break;
                    case TokenType::PLUS:
                        shift(p, lasttok, lookahead, stack, steps, 168); break;
                }
                break;
            case 212:
                switch (lookahead.type) {
                    default: {
                            auto a2 (pop_a<ASTNS::Expr>(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) :
                                Maybe<Location const>(a1);
                            Maybe<Location const> end =
                                a2 ? Maybe(a2->end()) :
                                Maybe<Location const>(a1);
std::unique_ptr<ASTNS::BinaryExpr> push (std::make_unique<ASTNS::BinaryExpr>(p.sourcefile, start, end, std::move(a0), a1, std::move(a2)));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_37, stack.back().state), std::move(pushitem), NonTerminal::_37);
                        }
                        break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 169); break;
                    case TokenType::PLUS:
                        shift(p, lasttok, lookahead, stack, steps, 168); break;
                }
                break;
            case 213:
                switch (lookahead.type) {
                    default: {
                            auto a2 (pop_a<ASTNS::Expr>(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) :
                                Maybe<Location const>(a1);
                            Maybe<Location const> end =
                                a2 ? Maybe(a2->end()) :
                                Maybe<Location const>(a1);
std::unique_ptr<ASTNS::BinaryExpr> push (std::make_unique<ASTNS::BinaryExpr>(p.sourcefile, start, end, std::move(a0), a1, std::move(a2)));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_38, stack.back().state), std::move(pushitem), NonTerminal::_38);
                        }
                        break;
                    case TokenType::PERCENT:
                        shift(p, lasttok, lookahead, stack, steps, 172); break;
                    case TokenType::SLASH:
                        shift(p, lasttok, lookahead, stack, steps, 171); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 170); break;
                }
                break;
            case 214:
                switch (lookahead.type) {
                    default: {
                            auto a2 (pop_a<ASTNS::Expr>(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) :
                                Maybe<Location const>(a1);
                            Maybe<Location const> end =
                                a2 ? Maybe(a2->end()) :
                                Maybe<Location const>(a1);
std::unique_ptr<ASTNS::BinaryExpr> push (std::make_unique<ASTNS::BinaryExpr>(p.sourcefile, start, end, std::move(a0), a1, std::move(a2)));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_38, stack.back().state), std::move(pushitem), NonTerminal::_38);
                        }
                        break;
                    case TokenType::PERCENT:
                        shift(p, lasttok, lookahead, stack, steps, 172); break;
                    case TokenType::SLASH:
                        shift(p, lasttok, lookahead, stack, steps, 171); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 170); break;
                }
                break;
            case 215:
                switch (lookahead.type) {
                    default: {
                            auto a2 (pop_a<ASTNS::Expr>(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) :
                                Maybe<Location const>(a1);
                            Maybe<Location const> end =
                                a2 ? Maybe(a2->end()) :
                                Maybe<Location const>(a1);
std::unique_ptr<ASTNS::BinaryExpr> push (std::make_unique<ASTNS::BinaryExpr>(p.sourcefile, start, end, std::move(a0), a1, std::move(a2)));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_39, stack.back().state), std::move(pushitem), NonTerminal::_39);
                        }
                        break;
                }
                break;
            case 216:
                switch (lookahead.type) {
                    default: {
                            auto a2 (pop_a<ASTNS::Expr>(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) :
                                Maybe<Location const>(a1);
                            Maybe<Location const> end =
                                a2 ? Maybe(a2->end()) :
                                Maybe<Location const>(a1);
std::unique_ptr<ASTNS::BinaryExpr> push (std::make_unique<ASTNS::BinaryExpr>(p.sourcefile, start, end, std::move(a0), a1, std::move(a2)));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_39, stack.back().state), std::move(pushitem), NonTerminal::_39);
                        }
                        break;
                }
                break;
            case 217:
                switch (lookahead.type) {
                    default: {
                            auto a2 (pop_a<ASTNS::Expr>(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) :
                                Maybe<Location const>(a1);
                            Maybe<Location const> end =
                                a2 ? Maybe(a2->end()) :
                                Maybe<Location const>(a1);
std::unique_ptr<ASTNS::BinaryExpr> push (std::make_unique<ASTNS::BinaryExpr>(p.sourcefile, start, end, std::move(a0), a1, std::move(a2)));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_39, stack.back().state), std::move(pushitem), NonTerminal::_39);
                        }
                        break;
                }
                break;
            case 218:
                switch (lookahead.type) {
                    default: {
                            auto a2 (pop_a<ASTNS::Type>(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) :
                                Maybe<Location const>(a1);
                            Maybe<Location const> end =
                                a2 ? Maybe(a2->end()) :
                                Maybe<Location const>(a1);
std::unique_ptr<ASTNS::CastExpr> push (std::make_unique<ASTNS::CastExpr>(p.sourcefile, start, end, std::move(a2), std::move(a0)));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_40, stack.back().state), std::move(pushitem), NonTerminal::_40);
                        }
                        break;
                }
                break;
            case 219:
                switch (lookahead.type) {
                    default: {
                            auto a2 (pop_a<ASTNS::Expr>(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                a2 ? Maybe(a2->end()) :
                                Maybe<Location const>(a1);
std::unique_ptr<ASTNS::AddrofExpr> push (std::make_unique<ASTNS::AddrofExpr>(p.sourcefile, start, end, a0, std::move(a2), true));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_41, stack.back().state), std::move(pushitem), NonTerminal::_41);
                        }
                        break;
                }
                break;
            case 220:
                switch (lookahead.type) {
                    case TokenType::CPARN:
                        shift(p, lasttok, lookahead, stack, steps, 236); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", stringify_token_type(TokenType::CPARN), "function call expression")  });
                }
                break;
            case 221:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::ArgList>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::ArgList> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_65, stack.back().state), std::move(pushitem), NonTerminal::_65);
                        }
                        break;
                }
                break;
            case 222:
                switch (lookahead.type) {
                    case TokenType::COMMA:
                        shift(p, lasttok, lookahead, stack, steps, 237); break;
                    default: {
                            auto a0 (pop_a<ASTNS::ArgList>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::ArgList> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_53, stack.back().state), std::move(pushitem), NonTerminal::_53);
                        }
                        break;
                }
                break;
            case 223:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::Arg>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
std::unique_ptr<ASTNS::ArgList> push(std::make_unique<ASTNS::ArgList>(p.sourcefile, start, end, std::vector<std::unique_ptr<ASTNS::Arg>> {}));

        push->args.push_back(std::move(a0));
                            std::unique_ptr<ASTNS::ArgList> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_54, stack.back().state), std::move(pushitem), NonTerminal::_54);
                        }
                        break;
                }
                break;
            case 224:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
std::unique_ptr<ASTNS::Arg> push (std::make_unique<ASTNS::Arg>(p.sourcefile, start, end, std::move(a0)));
                            std::unique_ptr<ASTNS::Arg> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_20, stack.back().state), std::move(pushitem), NonTerminal::_20);
                        }
                        break;
                }
                break;
            case 225:
                switch (lookahead.type) {
                    default: {
                            auto a2 (pop_t(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) :
                                Maybe<Location const>(a1);
                            Maybe<Location const> end =
                                Maybe<Location const>(a2);
std::unique_ptr<ASTNS::FieldAccessExpr> push (std::make_unique<ASTNS::FieldAccessExpr>(p.sourcefile, start, end, std::move(a0), a1, a2));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_43, stack.back().state), std::move(pushitem), NonTerminal::_43);
                        }
                        break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 238); break;
                }
                break;
            case 226:
                switch (lookahead.type) {
                    default: {
                            auto a2 (pop_t(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) :
                                Maybe<Location const>(a1);
                            Maybe<Location const> end =
                                Maybe<Location const>(a2);
std::unique_ptr<ASTNS::FieldAccessExpr> push (std::make_unique<ASTNS::FieldAccessExpr>(p.sourcefile, start, end, std::move(a0), a1, a2));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_43, stack.back().state), std::move(pushitem), NonTerminal::_43);
                        }
                        break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 239); break;
                }
                break;
            case 227:
                switch (lookahead.type) {
                    case TokenType::CPARN:
                        shift(p, lasttok, lookahead, stack, steps, 240); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", stringify_token_type(TokenType::CPARN), "function call expression")  });
                }
                break;
            case 228:
                switch (lookahead.type) {
                    default: {
                            auto a2 (pop_t(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) :
                                Maybe<Location const>(a1);
                            Maybe<Location const> end =
                                Maybe<Location const>(a2);
std::unique_ptr<ASTNS::FieldAccessExpr> push (std::make_unique<ASTNS::FieldAccessExpr>(p.sourcefile, start, end, std::move(a0), a1, a2));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_43, stack.back().state), std::move(pushitem), NonTerminal::_43);
                        }
                        break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 241); break;
                }
                break;
            case 229:
                switch (lookahead.type) {
                    default: {
                            auto a2 (pop_t(stack));
                            auto a1 (pop_a<ASTNS::Expr>(stack));
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                Maybe<Location const>(a2);
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(a1);
                            stack.emplace_back(get_goto(NonTerminal::_45, stack.back().state), std::move(pushitem), NonTerminal::_45);
                        }
                        break;
                }
                break;
            case 230:
                switch (lookahead.type) {
                    case TokenType::CCURB:
                        shift(p, lasttok, lookahead, stack, steps, 242); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", stringify_token_type(TokenType::CCURB), "braced code block")  });
                }
                break;
            case 231:
                switch (lookahead.type) {
                    default: {
                            auto a2 (pop_a<ASTNS::VarStmtItem>(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_a<ASTNS::VarStmtItemList>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) :
                                Maybe<Location const>(a1);
                            Maybe<Location const> end =
                                a2 ? Maybe(a2->end()) :
                                Maybe<Location const>(a1);
a0->items.push_back(std::move(a2));
                            std::unique_ptr<ASTNS::VarStmtItemList> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_57, stack.back().state), std::move(pushitem), NonTerminal::_57);
                        }
                        break;
                }
                break;
            case 232:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::VarStmtItem>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::VarStmtItem> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_55, stack.back().state), std::move(pushitem), NonTerminal::_55);
                        }
                        break;
                }
                break;
            case 233:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                        shift(p, lasttok, lookahead, stack, steps, 112); break;
                    case TokenType::BANG:
                        shift(p, lasttok, lookahead, stack, steps, 111); break;
                    case TokenType::BININTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 124); break;
                    case TokenType::CHARLIT:
                        shift(p, lasttok, lookahead, stack, steps, 126); break;
                    case TokenType::DECINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 122); break;
                    case TokenType::FALSELIT:
                        shift(p, lasttok, lookahead, stack, steps, 119); break;
                    case TokenType::FLOATLIT:
                        shift(p, lasttok, lookahead, stack, steps, 120); break;
                    case TokenType::HEXINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 125); break;
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::IF:
                        shift(p, lasttok, lookahead, stack, steps, 96); break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 110); break;
                    case TokenType::NULLPTRLIT:
                        shift(p, lasttok, lookahead, stack, steps, 121); break;
                    case TokenType::OCTINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 123); break;
                    case TokenType::OCURB:
                        shift(p, lasttok, lookahead, stack, steps, 76); break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 129); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 113); break;
                    case TokenType::STRINGLIT:
                        shift(p, lasttok, lookahead, stack, steps, 127); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 128); break;
                    case TokenType::TILDE:
                        shift(p, lasttok, lookahead, stack, steps, 109); break;
                    case TokenType::TRUELIT:
                        shift(p, lasttok, lookahead, stack, steps, 118); break;
                    case TokenType::WHILE:
                        shift(p, lasttok, lookahead, stack, steps, 97); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "expression", "variable binding")  });
                }
                break;
            case 234:
                switch (lookahead.type) {
                    default: {
                            auto a2 (pop_a<ASTNS::Type>(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                a2 ? Maybe(a2->end()) :
                                Maybe<Location const>(a1);
std::unique_ptr<ASTNS::VarStmtItem> push (std::make_unique<ASTNS::VarStmtItem>(p.sourcefile, start, end, std::move(a2), true, a1, a1, nullptr));
                            std::unique_ptr<ASTNS::VarStmtItem> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_10, stack.back().state), std::move(pushitem), NonTerminal::_10);
                        }
                        break;
                    case TokenType::EQUAL:
                        shift(p, lasttok, lookahead, stack, steps, 244); break;
                }
                break;
            case 235:
                switch (lookahead.type) {
                    case TokenType::IF:
                        shift(p, lasttok, lookahead, stack, steps, 96); break;
                    case TokenType::NEWLINE:
                        shift(p, lasttok, lookahead, stack, steps, 199); break;
                    case TokenType::OCURB:
                        shift(p, lasttok, lookahead, stack, steps, 76); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", format("either {} or {}", "code block", "if expression"), "if expression")  });
                }
                break;
            case 236:
                switch (lookahead.type) {
                    default: {
                            auto a3 (pop_t(stack));
                            auto a2 (pop_a<ASTNS::ArgList>(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) :
                                Maybe<Location const>(a1);
                            Maybe<Location const> end =
                                Maybe<Location const>(a3);
std::unique_ptr<ASTNS::CallExpr> push (std::make_unique<ASTNS::CallExpr>(p.sourcefile, start, end, std::move(a0), a1, std::move(a2->args)));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_42, stack.back().state), std::move(pushitem), NonTerminal::_42);
                        }
                        break;
                }
                break;
            case 237:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                        shift(p, lasttok, lookahead, stack, steps, 112); break;
                    case TokenType::BANG:
                        shift(p, lasttok, lookahead, stack, steps, 111); break;
                    case TokenType::BININTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 124); break;
                    case TokenType::CHARLIT:
                        shift(p, lasttok, lookahead, stack, steps, 126); break;
                    default: {
                            auto a1 (pop_t(stack));
                            auto a0 (pop_a<ASTNS::ArgList>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) :
                                Maybe<Location const>(a1);
                            Maybe<Location const> end =
                                Maybe<Location const>(a1);
                            std::unique_ptr<ASTNS::ArgList> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_53, stack.back().state), std::move(pushitem), NonTerminal::_53);
                        }
                        break;
                    case TokenType::DECINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 122); break;
                    case TokenType::FALSELIT:
                        shift(p, lasttok, lookahead, stack, steps, 119); break;
                    case TokenType::FLOATLIT:
                        shift(p, lasttok, lookahead, stack, steps, 120); break;
                    case TokenType::HEXINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 125); break;
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::IF:
                        shift(p, lasttok, lookahead, stack, steps, 96); break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 110); break;
                    case TokenType::NULLPTRLIT:
                        shift(p, lasttok, lookahead, stack, steps, 121); break;
                    case TokenType::OCTINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 123); break;
                    case TokenType::OCURB:
                        shift(p, lasttok, lookahead, stack, steps, 76); break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 129); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 113); break;
                    case TokenType::STRINGLIT:
                        shift(p, lasttok, lookahead, stack, steps, 127); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 128); break;
                    case TokenType::TILDE:
                        shift(p, lasttok, lookahead, stack, steps, 109); break;
                    case TokenType::TRUELIT:
                        shift(p, lasttok, lookahead, stack, steps, 118); break;
                    case TokenType::WHILE:
                        shift(p, lasttok, lookahead, stack, steps, 97); break;
                }
                break;
            case 238:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                        shift(p, lasttok, lookahead, stack, steps, 112); break;
                    case TokenType::BANG:
                        shift(p, lasttok, lookahead, stack, steps, 111); break;
                    case TokenType::BININTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 124); break;
                    case TokenType::CHARLIT:
                        shift(p, lasttok, lookahead, stack, steps, 126); break;
                    case TokenType::CPARN:
{
std::unique_ptr<ASTNS::ArgList> push (std::make_unique<ASTNS::ArgList>(p.sourcefile, Maybe<Location const>(), Maybe<Location const>(), std::vector<std::unique_ptr<ASTNS::Arg>> {}));
                            std::unique_ptr<ASTNS::ArgList> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_65, stack.back().state), std::move(pushitem), NonTerminal::_65);
                        }
                        break;
                    case TokenType::DECINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 122); break;
                    case TokenType::FALSELIT:
                        shift(p, lasttok, lookahead, stack, steps, 119); break;
                    case TokenType::FLOATLIT:
                        shift(p, lasttok, lookahead, stack, steps, 120); break;
                    case TokenType::HEXINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 125); break;
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::IF:
                        shift(p, lasttok, lookahead, stack, steps, 96); break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 110); break;
                    case TokenType::NULLPTRLIT:
                        shift(p, lasttok, lookahead, stack, steps, 121); break;
                    case TokenType::OCTINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 123); break;
                    case TokenType::OCURB:
                        shift(p, lasttok, lookahead, stack, steps, 76); break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 129); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 113); break;
                    case TokenType::STRINGLIT:
                        shift(p, lasttok, lookahead, stack, steps, 127); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 128); break;
                    case TokenType::TILDE:
                        shift(p, lasttok, lookahead, stack, steps, 109); break;
                    case TokenType::TRUELIT:
                        shift(p, lasttok, lookahead, stack, steps, 118); break;
                    case TokenType::WHILE:
                        shift(p, lasttok, lookahead, stack, steps, 97); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "optional argument list", "method call expression")  });
                }
                break;
            case 239:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                        shift(p, lasttok, lookahead, stack, steps, 112); break;
                    case TokenType::BANG:
                        shift(p, lasttok, lookahead, stack, steps, 111); break;
                    case TokenType::BININTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 124); break;
                    case TokenType::CHARLIT:
                        shift(p, lasttok, lookahead, stack, steps, 126); break;
                    case TokenType::CPARN:
{
std::unique_ptr<ASTNS::ArgList> push (std::make_unique<ASTNS::ArgList>(p.sourcefile, Maybe<Location const>(), Maybe<Location const>(), std::vector<std::unique_ptr<ASTNS::Arg>> {}));
                            std::unique_ptr<ASTNS::ArgList> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_65, stack.back().state), std::move(pushitem), NonTerminal::_65);
                        }
                        break;
                    case TokenType::DECINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 122); break;
                    case TokenType::FALSELIT:
                        shift(p, lasttok, lookahead, stack, steps, 119); break;
                    case TokenType::FLOATLIT:
                        shift(p, lasttok, lookahead, stack, steps, 120); break;
                    case TokenType::HEXINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 125); break;
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::IF:
                        shift(p, lasttok, lookahead, stack, steps, 96); break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 110); break;
                    case TokenType::NULLPTRLIT:
                        shift(p, lasttok, lookahead, stack, steps, 121); break;
                    case TokenType::OCTINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 123); break;
                    case TokenType::OCURB:
                        shift(p, lasttok, lookahead, stack, steps, 76); break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 129); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 113); break;
                    case TokenType::STRINGLIT:
                        shift(p, lasttok, lookahead, stack, steps, 127); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 128); break;
                    case TokenType::TILDE:
                        shift(p, lasttok, lookahead, stack, steps, 109); break;
                    case TokenType::TRUELIT:
                        shift(p, lasttok, lookahead, stack, steps, 118); break;
                    case TokenType::WHILE:
                        shift(p, lasttok, lookahead, stack, steps, 97); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "optional argument list", "method call expression")  });
                }
                break;
            case 240:
                switch (lookahead.type) {
                    default: {
                            auto a3 (pop_t(stack));
                            auto a2 (pop_a<ASTNS::ArgList>(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) :
                                Maybe<Location const>(a1);
                            Maybe<Location const> end =
                                Maybe<Location const>(a3);
std::unique_ptr<ASTNS::CallExpr> push (std::make_unique<ASTNS::CallExpr>(p.sourcefile, start, end, std::move(a0), a1, std::move(a2->args)));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_42, stack.back().state), std::move(pushitem), NonTerminal::_42);
                        }
                        break;
                }
                break;
            case 241:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                        shift(p, lasttok, lookahead, stack, steps, 112); break;
                    case TokenType::BANG:
                        shift(p, lasttok, lookahead, stack, steps, 111); break;
                    case TokenType::BININTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 124); break;
                    case TokenType::CHARLIT:
                        shift(p, lasttok, lookahead, stack, steps, 126); break;
                    case TokenType::CPARN:
{
std::unique_ptr<ASTNS::ArgList> push (std::make_unique<ASTNS::ArgList>(p.sourcefile, Maybe<Location const>(), Maybe<Location const>(), std::vector<std::unique_ptr<ASTNS::Arg>> {}));
                            std::unique_ptr<ASTNS::ArgList> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_65, stack.back().state), std::move(pushitem), NonTerminal::_65);
                        }
                        break;
                    case TokenType::DECINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 122); break;
                    case TokenType::FALSELIT:
                        shift(p, lasttok, lookahead, stack, steps, 119); break;
                    case TokenType::FLOATLIT:
                        shift(p, lasttok, lookahead, stack, steps, 120); break;
                    case TokenType::HEXINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 125); break;
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::IF:
                        shift(p, lasttok, lookahead, stack, steps, 96); break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 110); break;
                    case TokenType::NULLPTRLIT:
                        shift(p, lasttok, lookahead, stack, steps, 121); break;
                    case TokenType::OCTINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 123); break;
                    case TokenType::OCURB:
                        shift(p, lasttok, lookahead, stack, steps, 76); break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 129); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 113); break;
                    case TokenType::STRINGLIT:
                        shift(p, lasttok, lookahead, stack, steps, 127); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 128); break;
                    case TokenType::TILDE:
                        shift(p, lasttok, lookahead, stack, steps, 109); break;
                    case TokenType::TRUELIT:
                        shift(p, lasttok, lookahead, stack, steps, 118); break;
                    case TokenType::WHILE:
                        shift(p, lasttok, lookahead, stack, steps, 97); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "optional argument list", "method call expression")  });
                }
                break;
            case 242:
                switch (lookahead.type) {
                    default: {
                            auto a5 (pop_t(stack));
                            auto a4 (pop_t(stack));
                            auto a3 (pop_a<ASTNS::StmtList>(stack));
                            auto a2 (pop_t(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                Maybe<Location const>(a5);
std::unique_ptr<ASTNS::Block> push (std::make_unique<ASTNS::Block>(p.sourcefile, start, end, std::move(a3->stmts)));
                            std::unique_ptr<ASTNS::Block> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_13, stack.back().state), std::move(pushitem), NonTerminal::_13);
                        }
                        break;
                }
                break;
            case 243:
                switch (lookahead.type) {
                    default: {
                            auto a3 (pop_a<ASTNS::Expr>(stack));
                            auto a2 (pop_t(stack));
                            auto a1 (pop_a<ASTNS::Type>(stack));
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                a3 ? Maybe(a3->end()) :
                                Maybe<Location const>(a2);
std::unique_ptr<ASTNS::VarStmtItem> push (std::make_unique<ASTNS::VarStmtItem>(p.sourcefile, start, end, std::move(a1), false, a0, a2, std::move(a3)));
                            std::unique_ptr<ASTNS::VarStmtItem> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_10, stack.back().state), std::move(pushitem), NonTerminal::_10);
                        }
                        break;
                }
                break;
            case 244:
                switch (lookahead.type) {
                    case TokenType::AMPER:
                        shift(p, lasttok, lookahead, stack, steps, 112); break;
                    case TokenType::BANG:
                        shift(p, lasttok, lookahead, stack, steps, 111); break;
                    case TokenType::BININTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 124); break;
                    case TokenType::CHARLIT:
                        shift(p, lasttok, lookahead, stack, steps, 126); break;
                    case TokenType::DECINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 122); break;
                    case TokenType::FALSELIT:
                        shift(p, lasttok, lookahead, stack, steps, 119); break;
                    case TokenType::FLOATLIT:
                        shift(p, lasttok, lookahead, stack, steps, 120); break;
                    case TokenType::HEXINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 125); break;
                    case TokenType::IDENTIFIER:
                        shift(p, lasttok, lookahead, stack, steps, 18); break;
                    case TokenType::IF:
                        shift(p, lasttok, lookahead, stack, steps, 96); break;
                    case TokenType::MINUS:
                        shift(p, lasttok, lookahead, stack, steps, 110); break;
                    case TokenType::NULLPTRLIT:
                        shift(p, lasttok, lookahead, stack, steps, 121); break;
                    case TokenType::OCTINTLIT:
                        shift(p, lasttok, lookahead, stack, steps, 123); break;
                    case TokenType::OCURB:
                        shift(p, lasttok, lookahead, stack, steps, 76); break;
                    case TokenType::OPARN:
                        shift(p, lasttok, lookahead, stack, steps, 129); break;
                    case TokenType::STAR:
                        shift(p, lasttok, lookahead, stack, steps, 113); break;
                    case TokenType::STRINGLIT:
                        shift(p, lasttok, lookahead, stack, steps, 127); break;
                    case TokenType::THIS:
                        shift(p, lasttok, lookahead, stack, steps, 128); break;
                    case TokenType::TILDE:
                        shift(p, lasttok, lookahead, stack, steps, 109); break;
                    case TokenType::TRUELIT:
                        shift(p, lasttok, lookahead, stack, steps, 118); break;
                    case TokenType::WHILE:
                        shift(p, lasttok, lookahead, stack, steps, 97); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", "expression", "variable binding")  });
                }
                break;
            case 245:
                switch (lookahead.type) {
                    default: {
                            auto a4 (pop_a<ASTNS::Block>(stack));
                            auto a3 (pop_t(stack));
                            auto a2 (pop_a<ASTNS::Block>(stack));
                            auto a1 (pop_a<ASTNS::Expr>(stack));
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                a4 ? Maybe(a4->end()) :
                                Maybe<Location const>(a3);
std::unique_ptr<ASTNS::IfExpr> push (std::make_unique<ASTNS::IfExpr>(p.sourcefile, start, end, a0, a3, std::move(a1), std::move(a2), std::move(a4)));
                            std::unique_ptr<ASTNS::IfExpr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_27, stack.back().state), std::move(pushitem), NonTerminal::_27);
                        }
                        break;
                }
                break;
            case 246:
                switch (lookahead.type) {
                    default: {
                            auto a4 (pop_a<ASTNS::IfExpr>(stack));
                            auto a3 (pop_t(stack));
                            auto a2 (pop_a<ASTNS::Block>(stack));
                            auto a1 (pop_a<ASTNS::Expr>(stack));
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                a4 ? Maybe(a4->end()) :
                                Maybe<Location const>(a3);
std::unique_ptr<ASTNS::IfExpr> push (std::make_unique<ASTNS::IfExpr>(p.sourcefile, start, end, a0, a3, std::move(a1), std::move(a2), std::move(a4)));
                            std::unique_ptr<ASTNS::IfExpr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_27, stack.back().state), std::move(pushitem), NonTerminal::_27);
                        }
                        break;
                }
                break;
            case 247:
                switch (lookahead.type) {
                    default: {
                            auto a2 (pop_a<ASTNS::Arg>(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_a<ASTNS::ArgList>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) :
                                Maybe<Location const>(a1);
                            Maybe<Location const> end =
                                a2 ? Maybe(a2->end()) :
                                Maybe<Location const>(a1);
a0->args.push_back(std::move(a2));
                            std::unique_ptr<ASTNS::ArgList> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_54, stack.back().state), std::move(pushitem), NonTerminal::_54);
                        }
                        break;
                }
                break;
            case 248:
                switch (lookahead.type) {
                    default: {
                            auto a0 (pop_a<ASTNS::Arg>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) : Maybe<Location const>();
                            Maybe<Location const> end =
                                a0 ? Maybe(a0->end()) : Maybe<Location const>();
                            std::unique_ptr<ASTNS::Arg> pushitem = std::move(a0);
                            stack.emplace_back(get_goto(NonTerminal::_52, stack.back().state), std::move(pushitem), NonTerminal::_52);
                        }
                        break;
                }
                break;
            case 249:
                switch (lookahead.type) {
                    case TokenType::CPARN:
                        shift(p, lasttok, lookahead, stack, steps, 253); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", stringify_token_type(TokenType::CPARN), "method call expression")  });
                }
                break;
            case 250:
                switch (lookahead.type) {
                    case TokenType::CPARN:
                        shift(p, lasttok, lookahead, stack, steps, 254); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", stringify_token_type(TokenType::CPARN), "method call expression")  });
                }
                break;
            case 251:
                switch (lookahead.type) {
                    case TokenType::CPARN:
                        shift(p, lasttok, lookahead, stack, steps, 255); break;
                    default:
                        if (istrial) return false;
                        error(done, errored, errorstate(p, stack, lasttok, lookahead), std::vector<std::string> {  format("expected {} for {}", stringify_token_type(TokenType::CPARN), "method call expression")  });
                }
                break;
            case 252:
                switch (lookahead.type) {
                    default: {
                            auto a4 (pop_a<ASTNS::Expr>(stack));
                            auto a3 (pop_t(stack));
                            auto a2 (pop_a<ASTNS::Type>(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_t(stack));
                            Maybe<Location const> start =
                                Maybe<Location const>(a0);
                            Maybe<Location const> end =
                                a4 ? Maybe(a4->end()) :
                                Maybe<Location const>(a3);
std::unique_ptr<ASTNS::VarStmtItem> push (std::make_unique<ASTNS::VarStmtItem>(p.sourcefile, start, end, std::move(a2), true, a1, a3, std::move(a4)));
                            std::unique_ptr<ASTNS::VarStmtItem> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_10, stack.back().state), std::move(pushitem), NonTerminal::_10);
                        }
                        break;
                }
                break;
            case 253:
                switch (lookahead.type) {
                    default: {
                            auto a5 (pop_t(stack));
                            auto a4 (pop_a<ASTNS::ArgList>(stack));
                            auto a3 (pop_t(stack));
                            auto a2 (pop_t(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) :
                                Maybe<Location const>(a1);
                            Maybe<Location const> end =
                                Maybe<Location const>(a5);
std::unique_ptr<ASTNS::MethodCallExpr> push (std::make_unique<ASTNS::MethodCallExpr>(p.sourcefile, start, end, std::move(a0), a1, a2, a3, std::move(a4->args)));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_44, stack.back().state), std::move(pushitem), NonTerminal::_44);
                        }
                        break;
                }
                break;
            case 254:
                switch (lookahead.type) {
                    default: {
                            auto a5 (pop_t(stack));
                            auto a4 (pop_a<ASTNS::ArgList>(stack));
                            auto a3 (pop_t(stack));
                            auto a2 (pop_t(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) :
                                Maybe<Location const>(a1);
                            Maybe<Location const> end =
                                Maybe<Location const>(a5);
std::unique_ptr<ASTNS::MethodCallExpr> push (std::make_unique<ASTNS::MethodCallExpr>(p.sourcefile, start, end, std::move(a0), a1, a2, a3, std::move(a4->args)));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_44, stack.back().state), std::move(pushitem), NonTerminal::_44);
                        }
                        break;
                }
                break;
            case 255:
                switch (lookahead.type) {
                    default: {
                            auto a5 (pop_t(stack));
                            auto a4 (pop_a<ASTNS::ArgList>(stack));
                            auto a3 (pop_t(stack));
                            auto a2 (pop_t(stack));
                            auto a1 (pop_t(stack));
                            auto a0 (pop_a<ASTNS::Expr>(stack));
                            Maybe<Location const> start =
                                a0 ? Maybe(a0->start()) :
                                Maybe<Location const>(a1);
                            Maybe<Location const> end =
                                Maybe<Location const>(a5);
std::unique_ptr<ASTNS::MethodCallExpr> push (std::make_unique<ASTNS::MethodCallExpr>(p.sourcefile, start, end, std::move(a0), a1, a2, a3, std::move(a4->args)));
                            std::unique_ptr<ASTNS::Expr> pushitem = std::move(push);
                            stack.emplace_back(get_goto(NonTerminal::_44, stack.back().state), std::move(pushitem), NonTerminal::_44);
                        }
                        break;
                }
                break;
            default:
                report_abort_noh(format("Parser reached invalid state: {}", stack.back().state));
        }
    }
    // PARSERLOOP END }}}

    if (istrial)
        return true;

    if (errored) {
        p.errored = true;
        out = nullptr;
        return false;
    }

    stackitem topsi (std::move(stack.back()));
    ASSERT(std::holds_alternative<astitem>(topsi.item))

    astitem &ai = std::get<astitem>(topsi.item);
    std::unique_ptr<ASTNS::AST> astu (std::move(ai.ast));
    ASTNS::CUB *cub = static_cast<ASTNS::CUB*>(astu.release());
    out = std::unique_ptr<ASTNS::CUB>(cub);
    return true;
}
