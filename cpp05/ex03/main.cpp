/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranhaia- <ranhaia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 19:38:11 by ranhaia-          #+#    #+#             */
/*   Updated: 2026/06/02 19:15:58 by ranhaia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "[1] TESTANDO O ESTAGIÁRIO (INTERN)" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;

    Intern someRandomIntern;
    
    // Ponteiros que receberão os formulários alocados dinamicamente na Heap
    AForm* scf = NULL;
    AForm* rrf = NULL;
    AForm* ppf = NULL;
    AForm* unknown = NULL;

    // Testando a criação com sucesso
    scf = someRandomIntern.makeForm("shrubbery creation", "Jardim");
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    ppf = someRandomIntern.makeForm("presidential pardon", "Zaphod");

    // Testando a criação de um formulário inexistente (deve retornar NULL)
    unknown = someRandomIntern.makeForm("relatorio de ferias", "Chefe");

    std::cout << "\n--------------------------------------------------------" << std::endl;
    std::cout << "[2] TESTANDO ASSINATURAS E EXECUÇÕES" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;

    try
    {
        Bureaucrat boss("Chefe Supremo", 1);     // Pode tudo
        Bureaucrat intern("Ze Ninguem", 150);    // Não pode nada

        std::cout << boss << std::endl;
        std::cout << intern << std::endl;
        std::cout << std::endl;

        // Burocrata sem nível tenta assinar e executar
        if (scf)
        {
            std::cout << "--- Burocrata de nível baixo tentando agir ---" << std::endl;
            intern.signForm(*scf);
            intern.executeForm(*scf);
        }

        std::cout << std::endl;

        // Chefe assina e executa todos os formulários que foram criados com sucesso
        std::cout << "--- Burocrata de nível alto operando ---" << std::endl;
        if (scf)
        {
            boss.signForm(*scf);
            boss.executeForm(*scf);
        }
        if (rrf)
        {
            boss.signForm(*rrf);
            boss.executeForm(*rrf);
        }
        if (ppf)
        {
            boss.signForm(*ppf);
            boss.executeForm(*ppf);
        }
    }
    catch (std::exception &e)
    {
        // Esse catch pegaria erros na criação do Bureaucrat
        std::cerr << "Erro crítico e inesperado: " << e.what() << std::endl;
    }

    std::cout << "\n--------------------------------------------------------" << std::endl;
    std::cout << "[3] LIMPANDO A MEMÓRIA (DELETE)" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;

    // É obrigatório liberar a memória alocada pelo 'new' dentro do makeForm.
    // Usamos 'if' apenas como boa prática, pois o delete em um ponteiro NULL é seguro.
    if (scf)
        delete scf;
    
    if (rrf)
        delete rrf;
    
    if (ppf)
        delete ppf;
    
    // unknown já é NULL, então o delete não causaria problemas, mas é bom ignorar.

    std::cout << "Memória liberada com sucesso. Fim do programa." << std::endl;

    return 0;
}